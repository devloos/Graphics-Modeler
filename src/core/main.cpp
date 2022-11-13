#include "main.h"

#include <QtWidgets/QtWidgets>

#include "gm/vector.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  QWidget window;
  window.resize(640, 480);
  window.show();
  window.setWindowTitle(QApplication::translate("toplevel", "Top-level widget"));
  return app.exec();
}
