#pragma once

#include <QAction>
#include <QApplication>
#include <QMessageBox>
#include <QQmlEngine>
#include <QString>
#include <QtQmlIntegration>
#include <QtWidgets>
#include <iostream>

#include "qtmetamacros.h"
#include "utility/utility.h"

class CppInterface : public QObject {
  Q_OBJECT
  QML_ELEMENT
  QML_SINGLETON

 public:
  Q_INVOKABLE bool loginConnection(const QString &username, const QString &password) {
    std::string raw = (username + password).toStdString();
    std::size_t hash = std::hash<std::string>{}(raw);
    if (Utility::Login::isValid(hash)) {
      return true;
    }

    return false;
  };

  // Member getter and setter access from qml
  // Q_PROPERTY(QString coolString MEMBER coolString)
  // Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

  // signals:
  // void coolStringChanged();

  // public:
  // QString coolString = "SDKJALSDJLSKJ";

  // painter->setPen(QPen(Qt::white, 3, Qt::DashDotLine, Qt::RoundCap));
  // painter->setBrush(QBrush(Qt::green, Qt::SolidPattern));
  // painter->drawEllipse(0, 0, 240, 240);
};

// definition of the singleton type provider function (callback).
static QObject* singletonProvider(QQmlEngine* engine, QJSEngine* scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  CppInterface* example = new CppInterface();
  return example;
}
