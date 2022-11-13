#include "main.h"

// #include <QtWidgets/QtWidgets>
// #include <vector>

#include "stl/vector.h"

int main(int argc, char* argv[]) {
  // QApplication app(argc, argv);
  // QWidget window;
  // window.resize(640, 480);
  // window.show();
  // window.setWindowTitle(QApplication::translate("toplevel", "Top-level widget"));
  // return app.exec();

  GM::Vector<int> vec(10);

  GM::Vector<int> vec2 = vec;

  return 0;
}
