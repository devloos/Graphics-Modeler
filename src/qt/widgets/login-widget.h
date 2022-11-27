#pragma once
#include <QtCore/QPropertyAnimation>
#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QtWidgets>
#include <functional>
#include <string>

#include "gm/vector.h"
#include "gm/gm.h"
#include "utility/utility.h"

class LoginWidget : public QWidget {
 public:
  LoginWidget();
  virtual ~LoginWidget() noexcept;

 private:
  void stInvalid() noexcept;

 private:
  QLabel* header_ = nullptr;
  QFormLayout* form_ = nullptr;
  GM::Vector<QLineEdit*> fields_;
  QPushButton* loginBTN_ = nullptr;
};