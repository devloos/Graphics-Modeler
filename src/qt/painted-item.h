#ifndef PAINTEDITEM_H
#define PAINTEDITEM_H

#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>
#include <QtQuick/QQuickPaintedItem>
#include <iostream>

class PaintedItem : public QQuickPaintedItem
{

//        PaintedItem()
//        {
//
//        }

        void paint(QPainter *painter) override
        {
            //this->setRenderTarget(QQuickPaintedItem::Image);
            //this->setTextureSize(QSize(1000, 500));
            //this->update(QRect(0,0,1000,500));
            //std::cout << "Bruh" << std::endl;
            QColor white(245,0,255,255);
            QPen pen(white);
            painter->setPen(pen);
            painter->drawEllipse(0, 0, 100, 100);
            //this->update(QRect(0,0,1000,500));
        }

//        ~PaintedItem()
//        {

//        }
};

#endif // PAINTEDITEM_H
