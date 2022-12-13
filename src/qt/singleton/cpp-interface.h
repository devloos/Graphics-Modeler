#pragma once

#include <QAction>
#include <QApplication>
#include <QBrush>
#include <QFile>
#include <QMessageBox>
#include <QPen>
#include <QQmlEngine>
#include <QString>
#include <QTextStream>
#include <QVariantList>
#include <QtQmlIntegration>
#include <QtWidgets>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "gm/gm.h"
#include "gm/vector.h"
#include "models/shape.h"
#include "qtmetamacros.h"
#include "utility/utility.h"

extern std::vector<std::unique_ptr<Shape>> shapes;

class CppInterface : public QObject {
  Q_OBJECT
  QML_ELEMENT
  QML_SINGLETON

 public:
  Q_INVOKABLE bool loginConnection(const QString &username, const QString &password) {
    std::string raw = (username + password).toStdString();
    std::size_t hash = std::hash<std::string>{}(raw);
    if (Utility::Login::isValid(hash)) {
      return true;
    }

    return false;
  };

  Q_INVOKABLE void openFile(const QString &str) {
    QFile file(QUrl(str).toLocalFile());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      Utility::Debug::log("File was not able to be opened.");
      return;
    }

    QTextStream fin(&file);

    shapes.clear();
    Utility::Parser::parseShapes(shapes, fin);

    file.close();
  }

  Q_INVOKABLE QVariantList getProperties(const int &SHAPE) {
    QVariantList list;

    Shape* generic = shapes.at(SHAPE).get();
    list.push_back(QVariant(("Shape ID: " + std::to_string(SHAPE)).c_str()));
    list.push_back(QVariant(("Shape Name: " + generic->getShapeName())));

    std::string points = "Dimensions: ";
    for (auto &point : generic->getPoints()) {
      points.append(std::to_string(point.x()) + ", " + std::to_string(point.y()) + ", ");
    }
    list.push_back(QVariant(points.c_str()));

    if (SHAPE == GM::TEXT) {
      Text* text = (Text*)(shapes.at(SHAPE).get());
      list.push_back(QVariant(("TextColor: " + text->getColor()).c_str()));
      list.push_back(QVariant((
          "TextAlignment: " + QVariant::fromValue(text->getTextAlignment()).toString())));
      list.push_back(
          QVariant(("TextPointSize: " + std::to_string(text->getFontSize())).c_str()));
      list.push_back(QVariant(("TextFontFamily: " + text->getFontFamily()).c_str()));
      list.push_back(QVariant(
          "TextFontStyle: " + QVariant::fromValue(text->getFontStyle()).toString()));
      list.push_back(QVariant(
          "TextFontWeight: " + QVariant::fromValue(text->getFontWeight()).toString()));
      list.push_back(QVariant(("Width: " + std::to_string(text->getWidth())).c_str()));
      list.push_back(QVariant(("Length: " + std::to_string(text->getLength())).c_str()));

      return list;
    }

    QPen pen = generic->getPen();

    list.push_back(QVariant("PenColor: " + QVariant::fromValue(pen.color()).toString()));
    list.push_back(QVariant(("PenWidth: " + std::to_string(pen.width())).c_str()));
    list.push_back(QVariant("PenStyle: " + QVariant::fromValue(pen.style()).toString()));
    list.push_back(
        QVariant("PenCapStyle: " + QVariant::fromValue(pen.capStyle()).toString()));
    list.push_back(
        QVariant("PenJoinStyle: " + QVariant::fromValue(pen.joinStyle()).toString()));

    if (SHAPE != GM::LINE && SHAPE != GM::POLYLINE) {
      QBrush brush = pen.brush();
      list.push_back(
          QVariant("BrushColor: " + QVariant::fromValue(brush.color()).toString()));
      list.push_back(
          QVariant("BrushStyle: " + QVariant::fromValue(brush.style()).toString()));
    }

    switch (SHAPE) {
      case GM::RECTANGLE: {
        Rectangle* rec = (Rectangle*)(shapes.at(SHAPE).get());
        list.push_back(QVariant(("Width: " + std::to_string(rec->getWidth())).c_str()));
        list.push_back(QVariant(("Length: " + std::to_string(rec->getLength())).c_str()));
        break;
      }

      case GM::SQUARE: {
        Square* square = (Square*)(shapes.at(SHAPE).get());
        list.push_back(
            QVariant(("Length: " + std::to_string(square->getLength())).c_str()));
        break;
      }

      case GM::ELLIPSE: {
        Ellipse* ellipse = (Ellipse*)(shapes.at(SHAPE).get());
        list.push_back(QVariant(
            ("SemiMajorAxis: " + std::to_string(ellipse->getMajorAxis())).c_str()));
        list.push_back(QVariant(
            ("SemiMinorAxis: " + std::to_string(ellipse->getMinorAxis())).c_str()));
        break;
      }

      case GM::CIRCLE: {
        Circle* circle = (Circle*)(shapes.at(SHAPE).get());
        list.push_back(
            QVariant(("Radius: " + std::to_string(circle->getRadius())).c_str()));
        break;
      }

      default: {
        break;
      }
    }

    return list;
  }

  Q_INVOKABLE void runReport() {
    QFile file("qrc:/report.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      Utility::Debug::log("File was not able to be opened.");
      return;
    }

    QTextStream fout(&file);

    selection_sort(shapes);

    for (const auto &shape : shapes) {
      QVariantList list = getProperties(shape->getShapeId() - 1);

      for (const auto &property : list) {
        fout << property.toString() << "\n";
      }
      fout << "\n";
    }

    file.close();
  }

  void selection_sort(std::vector<std::unique_ptr<Shape>> &vec) {
    using it = typename std::vector<std::unique_ptr<Shape>>::iterator;
    for (it itor = vec.begin(); itor != vec.end(); ++itor) {
      it minItor = itor;
      for (it i = itor + 1; i != vec.end(); ++i) {
        if (i->get()->getShapeId() < minItor->get()->getShapeId()) {
          minItor = i;
        }
      }
      if (minItor != itor) {
        std::iter_swap(itor, minItor);
      }
    }
  }
};

// definition of the singleton type provider function (callback).
static QObject* singletonProvider(QQmlEngine* engine, QJSEngine* scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  CppInterface* singleton = new CppInterface();
  return singleton;
}
