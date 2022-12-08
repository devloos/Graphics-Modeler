#pragma once

#include <QAction>
#include <QApplication>
#include <QBrush>
#include <QQuickPaintedItem>
#include <QString>
#include <QtWidgets>
#include <iostream>

class PaintedItem : public QQuickPaintedItem {
  Q_OBJECT

 public:
  explicit PaintedItem(QQuickItem* parent = 0) : QQuickPaintedItem(parent) {}

 public:
  void paint(QPainter* painter) override {
    std::cout << "BRUHHHHHH\n";
    // // Отрисовка объекта
    // QBrush brush(m_backgroundColor);                // Choose a background color, ...
    // QBrush brushActive(m_borderActiveColor);        // active color of border, ...
    // QBrush brushNonActive(m_borderNonActiveColor);  // not active color of border

    // painter->setPen(Qt::NoPen);                             // remove the outline
    // painter->setRenderHints(QPainter::Antialiasing, true);  // Enable antialiasing

    // painter->setBrush(brushNonActive);  // Draw the lowest background in a circle
    // painter->drawEllipse(boundingRect().adjusted(
    //     1, 1, -1, -1));  // with adjustment to the current dimensions, which
    //                      // will be determined in QML-layer.
    //                      // It will not be an active background rim

    // // The progress bar will be formed by drawing Pie chart
    // painter->setBrush(brushActive);  // Draw rim active in the background, depending on
    //                                  // the angle of rotation
    // painter->drawPie(
    //     boundingRect().adjusted(1, 1, -1, -1),  // to fit to the size of the layer in
    //     QML 90 * 16,                                // The starting point m_angle *
    //     16);  // the angle of rotation, which is necessary to render the object

    // painter->setBrush(brush);  // the basic background of the timer, which overlap on
    // top painter->drawEllipse(boundingRect().adjusted(
    //     10, 10, -10, -10));  // Border (aka the progress bar) will be formed
    // QColor white(245, 0, 255, 255);

    // QPen pen(white);
    // painter->setPen(pen);
    // painter->drawEllipse(0, 0, 100, 100);
  }
};
