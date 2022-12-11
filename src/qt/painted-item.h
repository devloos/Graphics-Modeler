#pragma once

#include <QAction>
#include <QApplication>
#include <QBrush>
#include <QQuickPaintedItem>
#include <QString>
#include <QtWidgets>
#include <iostream>

#include "qtmetamacros.h"

class EllipseTest : public QQuickPaintedItem {
  Q_OBJECT

 public:
  explicit EllipseTest(QQuickItem* parent = 0) : QQuickPaintedItem(parent) {}

 public:
  Q_INVOKABLE void paint(QPainter* painter) override {
    std::cout << "ELLIPSE\n";
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::white, 3, Qt::DashDotLine, Qt::RoundCap));
    painter->setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter->drawEllipse(0, 0, 240, 240);
  }

  // Member getter and setter access from qml
  // Q_PROPERTY(QString coolString MEMBER coolString)
  // Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

  // signals:
  // void coolStringChanged();

  // public:
  // QString coolString = "SDKJALSDJLSKJ";
};

class SquareTest : public QQuickPaintedItem {
  Q_OBJECT

 public:
  explicit SquareTest(QQuickItem* parent = 0) : QQuickPaintedItem(parent) {
    std::cout << "SQUARE\n";
  }

 public:
  void paint(QPainter* painter) override {
    painter->setPen(QPen(Qt::white, 3, Qt::DashDotLine, Qt::RoundCap));
    painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter->drawRect(0, 0, 240, 240);
  }
};
