#pragma once
#include <QtCore/QPropertyAnimation>
#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QtWidgets>
#include <functional>
#include <string>

#include "gm/gm.h"
#include "gm/vector.h"
#include "utility/utility.h"

class LoginWidget : public QWidget {
 public:
  LoginWidget();
  virtual ~LoginWidget() noexcept;

 private:
  void initForm();
  void statusInvalid() noexcept;
  void setFormFields();
  void setFormConnection() noexcept;

 private:
  void initInfoPane();

 private:
  // Form Widget
  QWidget* formWidget_ = nullptr;
  QLabel* header_ = nullptr;
  QFormLayout* form_ = nullptr;
  GM::Vector<QLineEdit*> fields_;
  QPushButton* loginBTN_ = nullptr;

  // Contact Widget
  QWidget* infoPaneWidget_ = nullptr;
  QLabel* logo_ = nullptr;
  QMessageBox* infoMsg_ = nullptr;
  QPushButton* contactBTN_ = nullptr;
};