#include "main.h"

MainWidget::MainWidget() {
  setAutoFillBackground(true);
  setPalette(QPalette(QColor(34, 50, 77)));

  QLabel* label = new QLabel(this);

  label->setGeometry(
      (GM::Window::WIDTH / 2) - 160, (GM::Window::HEIGHT / 2) - 25, 350, 50);
  label->setText("IN PROGRESS");
  label->setStyleSheet("font-size: 50px");
}

MainWidget::~MainWidget() noexcept {}