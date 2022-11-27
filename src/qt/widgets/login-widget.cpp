#include "login-widget.h"

#include "qt/main-window.h"

LoginWidget::LoginWidget()
    : form_(new QFormLayout(this)),
      loginBTN_(new QPushButton("Login", this)),
      header_(
          new QLabel(QObject::tr("<div align='center'><strong>Login</strong></div>"))) {
  form_->setGeometry(QRect(
      QPoint((GM::Window::WIDTH / 2) - 140, (GM::Window::HEIGHT / 2) - 85),
      QSize(280, 170)));

  form_->addRow(header_);

  QLineEdit* lineInput = new QLineEdit(this);
  form_->addRow(QString("Username: "), lineInput);
  fields_.push_back(lineInput);

  lineInput = new QLineEdit(this);
  form_->addRow(QString("Password: "), lineInput);
  fields_.push_back(lineInput);

  form_->addRow(loginBTN_);
  QObject::connect(loginBTN_, &QPushButton::clicked, this, [this]() {
    std::string raw = (fields_[0]->text() + fields_[1]->text()).toStdString();
    std::size_t hash = std::hash<std::string>{}(raw);
    if (Utility::Login::isValid(hash)) {
      MainWindow* parent = (MainWindow*)this->parent();
      delete parent->centralWidget();
      parent->setCentralWidget(parent->getMainWidget());
      return;
    }

    stInvalid();
  });
}

LoginWidget::~LoginWidget() noexcept {
  delete form_;
  delete loginBTN_;
  delete header_;
  for (QLineEdit* edit : fields_) {
    delete edit;
  }
}

void LoginWidget::stInvalid() noexcept {
  QMessageBox qm(this);
  qm.setGeometry(QRect(0, 125, 60, 20));
  qm.setWindowFlags(Qt::WindowCloseButtonHint);
  qm.setStandardButtons(QMessageBox::NoButton);
  qm.setText("Incorrect Username or Password.");
  QTimer::singleShot(2000, this, [&qm]() { qm.done(0); });
  qm.exec();
}