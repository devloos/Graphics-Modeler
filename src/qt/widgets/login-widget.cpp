#include "login-widget.h"

#include "qt/main-window.h"

LoginWidget::LoginWidget() {
  this->setAutoFillBackground(true);
  this->setPalette(QPalette(QColor(31, 31, 31)));

  initForm();
  initInfoPane();
}

LoginWidget::~LoginWidget() noexcept {
  // Deallocating Form Widget
  delete loginBTN_;
  for (QLineEdit* edit : fields_) {
    delete edit;
  }
  delete header_;
  delete form_;
  delete formWidget_;
  // Deallocating Form Widget

  // Deallocating Info Pane Widget
  delete contactBTN_;
  delete infoMsg_;
  delete logo_;
  delete infoPaneWidget_;
  // Deallocating Info Pane Widget
}

void LoginWidget::statusInvalid() noexcept {
  QMessageBox qm(this);
  qm.setGeometry(QRect(17, 260, 60, 20));
  qm.setWindowFlags(Qt::WindowCloseButtonHint);
  qm.setStandardButtons(QMessageBox::NoButton);
  qm.setText("Incorrect Username or Password.");
  QTimer::singleShot(2000, this, [&qm]() { qm.done(0); });
  qm.exec();
}

void LoginWidget::setFormFields() {
  form_->addRow(header_);

  QLineEdit* lineInput = new QLineEdit(formWidget_);
  form_->addRow(QString("Username: "), lineInput);
  fields_.push_back(lineInput);

  lineInput = new QLineEdit(formWidget_);
  form_->addRow(QString("Password: "), lineInput);
  fields_.push_back(lineInput);

  form_->addRow(loginBTN_);
}

void LoginWidget::setFormConnection() noexcept {
  QObject::connect(loginBTN_, &QPushButton::clicked, formWidget_, [this]() {
    std::string raw = (fields_[0]->text() + fields_[1]->text()).toStdString();
    std::size_t hash = std::hash<std::string>{}(raw);
    if (Utility::Login::isValid(hash)) {
      MainWindow* parent = (MainWindow*)this->parent();
      delete parent->centralWidget();
      parent->setCentralWidget(parent->getMainWidget());
      return;
    }

    statusInvalid();
  });
}

void LoginWidget::initForm() {
  formWidget_ = new QWidget(this);
  formWidget_->setGeometry(QRect(
      QPoint((GM::Window::WIDTH / 2) - 280, (GM::Window::HEIGHT / 2) - 120),
      QSize(240, 240)));
  formWidget_->setAutoFillBackground(true);
  formWidget_->setPalette(QPalette(QColor(31, 31, 31)));

  form_ = new QFormLayout(formWidget_);
  loginBTN_ = new QPushButton("Login", formWidget_);
  header_ =
      new QLabel(QObject::tr("<div align='center'>"
                             "<strong>Login</strong>"
                             "<br />"
                             "</div>"));

  setFormFields();
  setFormConnection();
}

void LoginWidget::initInfoPane() {
  infoPaneWidget_ = new QWidget(this);
  infoPaneWidget_->setGeometry(
      QRect(QPoint((GM::Window::WIDTH / 2), 0), QSize(320, GM::Window::HEIGHT)));
  infoPaneWidget_->setAutoFillBackground(true);
  infoPaneWidget_->setPalette(QPalette(QColor(102, 102, 102)));

  logo_ = new QLabel(infoPaneWidget_);
  logo_->setPixmap(QPixmap((Utility::ASSETS_PATH.string() + "/agile.png").c_str()));
  logo_->setGeometry(QRect(QPoint(130, 110), QSize(58, 58)));

  infoMsg_ = new QMessageBox(infoPaneWidget_);
  infoMsg_->setGeometry(QRect(QPoint(20, 170), QSize(80, 120)));
  infoMsg_->setWindowFlags(Qt::WindowCloseButtonHint);
  infoMsg_->setStandardButtons(QMessageBox::NoButton);
  infoMsg_->setText(
      "<div align='center'>We are here to revolutionize<br/>"
      "the world, one shape at a time.<br/>"
      "Critics say, \"The DEMO is out of<br/>"
      "this world!\"<br/></div>");

  contactBTN_ = new QPushButton(infoPaneWidget_);
  contactBTN_->setGeometry(QRect(QPoint(120, 260), QSize(80, 30)));
  contactBTN_->setAutoFillBackground(true);
  contactBTN_->setPalette(QPalette(QColor(85, 118, 171)));
  contactBTN_->setText("Contact us");

  QObject::connect(contactBTN_, &QPushButton::clicked, infoPaneWidget_, [this]() {
    QMessageBox::information(
        this, "About us",
        "<div align='center'>"
        "We are the shadows in the night.<br />"
        "The ones who are not afraid to fight.<br />"
        "Fighting only for what is right.<br />"
        "WE ARE THE SCRUMMY BOYS!"
        "</div>");
  });
}
