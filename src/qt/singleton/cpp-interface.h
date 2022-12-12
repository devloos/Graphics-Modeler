#pragma once

#include <QAction>
#include <QApplication>
#include <QBrush>
#include <QMessageBox>
#include <QPen>
#include <QQmlEngine>
#include <QString>
#include <QVariantList>
#include <QtQmlIntegration>
#include <QtWidgets>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "gm/gm.h"
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

    // switch (SHAPE) {
    //   case GM::LINE:
    //   case GM::POLYLINE: {
    //     list.push_back(QVariant("PenColor: " + ))
    //     break;
    //   }

    //   case GM::POLYGON:
    //   case GM::RECTANGLE:
    //   case GM::SQUARE:
    //   case GM::ELLIPSE:
    //   case GM::CIRCLE: {
    //     break;
    //   }

    //   case GM::TEXT: {
    //     break;
    //   }

    //   default: {
    //     break;
    //   }
    // }

    return list;
  }
};

// definition of the singleton type provider function (callback).
static QObject* singletonProvider(QQmlEngine* engine, QJSEngine* scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  CppInterface* example = new CppInterface();
  return example;
}
