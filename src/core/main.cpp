#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>
#include <memory>
#include <vector>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickPaintedItem>

#include "gm/vector.h"
#include "models/shape.h"
#include "qt/main-window.h"
#include "qt/painted-item.h"
#include "utility/utility.h"
#include "qt/qtCallTest.h"


int main(int argc, char* argv[]) {

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/login-window.qml"_qs);

    QObject::connect(
                &engine, &QQmlApplicationEngine::objectCreated, &app,
                [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    },
    Qt::QueuedConnection);

    qmlRegisterType<PaintedItem>("My.Items", 1, 0, "EllipseShape");
    qmlRegisterSingletonType<CppInterface>("My.Bruh", 1, 0, "CppInterface", singletonProvider);

    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    QCoreApplication::setOrganizationName("Scrummy Boys");
    QCoreApplication::setApplicationName("Graphics Modeler");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);


    //std::vector<std::unique_ptr<Shape>> shapes;
    //Utility::Parser::parseShapes(shapes);

    return app.exec();
}
