#pragma once
#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QtWidgets>

#include "gm/vector.h"

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