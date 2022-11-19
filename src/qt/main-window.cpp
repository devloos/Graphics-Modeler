#include "main-window.h"

MainWindow::MainWindow() {
  this->setFixedSize(QSize(WIDTH, HEIGHT));
  QPushButton* button = new QPushButton("New Window", this);
  button->setGeometry(QRect(QPoint((WIDTH / 2) - 45, (HEIGHT / 2) - 20), QSize(90, 40)));

  MainWindow::connect(button, &QPushButton::clicked, this, &MainWindow::login);
}

void stInvalid(QDialog &dialog) {
  QMessageBox qm(&dialog);
  qm.setGeometry(QRect(0, 125, 60, 20));
  qm.setWindowFlags(Qt::WindowCloseButtonHint);
  qm.setStandardButtons(QMessageBox::NoButton);
  qm.setText("Incorrect Username or Password.");
  QTimer::singleShot(2000, &dialog, [&qm]() { qm.done(0); });
  qm.exec();
}

void MainWindow::login() {
  QDialog dialog(this);
  dialog.setFixedSize(QSize(280, 170));

  QFormLayout form(&dialog);

  form.addRow(
      new QLabel(QObject::tr("<div align='center'><strong>Login</strong></div>")));

  GM::Vector<QLineEdit*> fields;

  QLineEdit* lineEdit = new QLineEdit(&dialog);
  form.addRow(QString("Username: "), lineEdit);
  fields.push_back(lineEdit);

  lineEdit = new QLineEdit(&dialog);
  form.addRow(QString("Password: "), lineEdit);
  fields.push_back(lineEdit);

  QPushButton* button = new QPushButton("Login", &dialog);
  form.addRow(button);
  QObject::connect(button, &QPushButton::clicked, &dialog, [&dialog, &fields]() {
    std::size_t hash =
        std::hash<std::string>{}((fields[0]->text() + fields[1]->text()).toStdString());
    if (Utility::Login::isValid(hash)) {
      dialog.accept();
    }

    stInvalid(dialog);
  });

  if (dialog.exec() == QDialog::Rejected) {
    this->close();
  }
}

void MainWindow::closeEvent(QCloseEvent* event) {}

void MainWindow::commitData(QSessionManager &) {}