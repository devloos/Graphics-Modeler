#pragma once
#include <QtCore/QPropertyAnimation>
#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QtWidgets>
#include <functional>
#include <string>

#include "gm/vector.h"
#include "login-widget.h"
#include "main-widget.h"
#include "utility/utility.h"
#include "utility/window.h"

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();
  virtual ~MainWindow() noexcept;

 public:
  MainWidget* getMainWidget();

 protected:
  void closeEvent(QCloseEvent* event) override;

 private slots:

#ifndef QT_NO_SESSIONMANAGER
  void commitData(QSessionManager &);
#endif

 private:
  LoginWidget* login_ = nullptr;
  MainWidget* demo_ = nullptr;
};