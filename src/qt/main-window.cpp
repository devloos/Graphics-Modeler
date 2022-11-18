#include "main-window.h"

MainWindow::MainWindow() {
  this->resize(WIDTH, HEIGHT);

  QPushButton* button = new QPushButton("New Window", this);
  button->setGeometry(QRect(QPoint((WIDTH / 2) - 45, (HEIGHT / 2) - 20), QSize(90, 40)));

  MainWindow::connect(button, &QPushButton::clicked, this, &MainWindow::login);
}

void MainWindow::login() {
  QDialog dialog(this);
  QFormLayout form(&dialog);

  form.addRow(new QLabel(QObject::tr("<div align='center'>Login</div>")));

  GM::Vector<QLineEdit*> fields;

  QLineEdit* lineEdit = new QLineEdit(&dialog);
  form.addRow(QString("Username: "), lineEdit);
  fields.push_back(lineEdit);

  lineEdit = new QLineEdit(&dialog);
  form.addRow(QString("Password: "), lineEdit);
  fields.push_back(lineEdit);

  QPushButton* button = new QPushButton("Login", &dialog);
  form.addRow(button);
  QObject::connect(
      button, &QPushButton::clicked, &dialog, [&dialog]() { dialog.accept(); });

  dialog.exec();
}

void MainWindow::closeEvent(QCloseEvent* event) {}

void MainWindow::commitData(QSessionManager &) {}