#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>
#include <memory>
#include <vector>

#include "gm/vector.h"
#include "models/shape.h"
#include "qt/main-window.h"
#include "utility/utility.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QCoreApplication::setOrganizationName("Srummy Boys");
  QCoreApplication::setApplicationName("Graphics Modeler");
  QCoreApplication::setApplicationVersion(QT_VERSION_STR);

  // std::vector<std::unique_ptr<Shape>> shapes;
  // Utility::Parser::parseShapes(shapes);

  MainWindow window;
  window.show();

  return app.exec();
}