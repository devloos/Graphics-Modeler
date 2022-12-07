#include "qqmlengine.h"
#include "qtmetamacros.h"
#pragma Singleton

#include "qqmlintegration.h"
#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>
#include <iostream>

class CppInterface : public QObject
{
public:
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON



    Q_INVOKABLE void bruh()
    {
        std::cout << "dasdasdsdafasddasadasdasdas" << std::endl;
    };

    Q_PROPERTY(QString wowStr MEMBER coolString NOTIFY coolStringChanged)

signals:
    void coolStringChanged();


public:
    QString coolString = "SDKJALSDJLSKJ";



};

// Second, define the singleton type provider function (callback).
static QObject *singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    CppInterface *example = new CppInterface();
    return example;
}


