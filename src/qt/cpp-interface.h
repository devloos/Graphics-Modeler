#pragma once
#include "qqmlengine.h"
#include "qtmetamacros.h"
#include "qqmlintegration.h"
#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>
#include <iostream>

class CppInterface : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:

    // Call be called from qml
    Q_INVOKABLE void callMe()
    {
        std::cout << "Hello_World" << std::endl;
    };

    // Member getter and setter access from qml
    //Q_PROPERTY(QString coolString MEMBER coolString)
    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

//signals:
    //void coolStringChanged();

//public:
    //QString coolString = "SDKJALSDJLSKJ";
};


// definition of the singleton type provider function (callback).
static QObject *singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    CppInterface *example = new CppInterface();
    return example;
}


