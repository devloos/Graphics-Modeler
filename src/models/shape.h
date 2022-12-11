#pragma once

#include <QAction>
#include <QApplication>
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QQuickPaintedItem>
#include <QString>
#include <QtWidgets>
#include <string>

#include "gm/vector.h"
#include "qtmetamacros.h"

class Shape : public QQuickPaintedItem {
  Q_OBJECT

 public:
  explicit Shape(QQuickItem* parent = 0);
  Shape(int id, const QString &name, const QPen &pen);
  virtual ~Shape() noexcept;

 public:
  void setPenStyle(Qt::PenStyle style);
  void setPenCap(Qt::PenCapStyle cap);
  void setPenColor(QColor color);
  void setPenJoin(Qt::PenJoinStyle joinStyle);
  void setPenWidth(int width);
  void setPenBrush(const QBrush &brush);
  void setShapeName(const QString &name);
  void setShapeId(int id);

 public:
  QPoint &getPointAt(int x);
  GM::Vector<QPoint> &getPoints();
  int getShapeId() const;
  QString getShapeName() const;
  QBrush getPenBrush() const;

 public:
  void pushPoint(QPoint newPoint);
  void popPoint();

 public:
  virtual void paint(QPainter* painter) override = 0;
  virtual float area() const = 0;
  virtual float perimeter() const = 0;

 private:
  int id_ = 0;
  QString name_;
  QPen pen_;
  GM::Vector<QPoint> points_;
};
