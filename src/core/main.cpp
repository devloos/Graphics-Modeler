#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>

#include "gm/vector.h"
#include "qt/main-window.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QCoreApplication::setOrganizationName("Srummy Boys");
  QCoreApplication::setApplicationName("Graphics Modeler");
  QCoreApplication::setApplicationVersion(QT_VERSION_STR);

  MainWindow window;
  window.show();

  return app.exec();
}