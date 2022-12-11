#include "main.h"

int main(int argc, char* argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url(u"qrc:/App.qml"_qs);

  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject* obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);

  // Register C++ interface singleton and shapes to be accessible within qml
  qmlRegisterType<Line>("My.Shapes", 1, 0, "GMLine");
  qmlRegisterType<Polyline>("My.Shapes", 1, 0, "GMPolyline");
  qmlRegisterType<Polygon>("My.Shapes", 1, 0, "GMPolygon");
  qmlRegisterType<Rectangle>("My.Shapes", 1, 0, "GMRectangle");
  qmlRegisterType<Square>("My.Shapes", 1, 0, "GMSquare");
  qmlRegisterType<Ellipse>("My.Shapes", 1, 0, "GMEllipse");
  qmlRegisterType<Circle>("My.Shapes", 1, 0, "GMCircle");
  qmlRegisterType<Text>("My.Shapes", 1, 0, "GMText");

  qmlRegisterSingletonType<CppInterface>(
      "My.Singletons", 1, 0, "CppInterface", singletonProvider);

  engine.load(url);

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  QCoreApplication::setOrganizationName("Scrummy Boys");
  QCoreApplication::setApplicationName("Graphics Modeler");
  QCoreApplication::setApplicationVersion(QT_VERSION_STR);

  // std::vector<std::unique_ptr<Shape>> shapes;
  // Utility::Parser::parseShapes(shapes);

  return app.exec();
}
