#pragma once
#include <QtCore/QPropertyAnimation>
#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QtWidgets>
#include <functional>
#include <string>

#include "gm/vector.h"
#include "utility/utility.h"

static const int WIDTH = 640;
static const int HEIGHT = 480;

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();

 protected:
  void closeEvent(QCloseEvent* event) override;

 private slots:

#ifndef QT_NO_SESSIONMANAGER
  void commitData(QSessionManager &);
#endif

 private:
  void login();

 private:
};