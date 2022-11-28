#include "main-window.h"

MainWindow::MainWindow()
    : loginWidget_(new LoginWidget()), demoWidget_(new MainWidget()) {
  this->setFixedSize(QSize(GM::Window::WIDTH, GM::Window::HEIGHT));

  loginWidget_->setFixedSize(QSize(GM::Window::WIDTH, GM::Window::HEIGHT));
  demoWidget_->setFixedSize(QSize(GM::Window::WIDTH, GM::Window::HEIGHT));

  this->setCentralWidget(loginWidget_);
}

MainWindow::~MainWindow() noexcept {
  delete demoWidget_;
}

void MainWindow::closeEvent(QCloseEvent* event) {}

void MainWindow::commitData(QSessionManager &) {}

MainWidget* MainWindow::getMainWidget() {
  return demoWidget_;
}