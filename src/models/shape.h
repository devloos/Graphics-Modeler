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
  /**
   * @brief Construct a new Shape object
   *
   * @param parent
   */
  explicit Shape(QQuickItem* parent = 0);

  /**
   * @brief Construct a new Shape object
   *
   * @param id
   * @param name
   * @param pen
   */
  Shape(int id, const QString &name, const QPen &pen);

  /**
   * @brief Destroy the Shape object
   *
   */
  virtual ~Shape() noexcept;

 public:
  // Setters
  void setPenStyle(Qt::PenStyle style);
  void setPenCap(Qt::PenCapStyle cap);
  void setPenColor(QColor color);
  void setPenJoin(Qt::PenJoinStyle joinStyle);
  void setPenWidth(int width);
  void setPenBrush(const QBrush &brush);
  void setShapeName(const QString &name);
  void setShapeId(int id);

 public:
  // Getters
  QPoint &getPointAt(int x);
  GM::Vector<QPoint> &getPoints();
  int getShapeId() const;
  QString getShapeName() const;
  QBrush getPenBrush() const;
  QPen &getPen();

 public:
  /**
   * @brief adds a new point
   *
   * @param newPoint
   */
  void pushPoint(QPoint newPoint);

  /**
   * @brief removes a point
   *
   */
  void popPoint();

 public:
  /**
   * @brief PURE VIRTUAL
   *
   * @param painter
   */
  virtual void paint(QPainter* painter) override = 0;

  /**
   * @brief PURE VIRTUAL - returns the area of a shape
   *
   * @return float
   */
  virtual float area() const = 0;

  /**
   * @brief PURE VIRTUAL - returns the perimeter of a shape
   *
   * @return float
   */
  virtual float perimeter() const = 0;

 protected:
  int id_ = 0;
  QString name_;
  QPen pen_;
  GM::Vector<QPoint> points_;
};
