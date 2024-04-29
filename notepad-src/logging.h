#pragma once

#include "file.h"

#include <QApplication>
#include <QDateTime>
#include <QObject>

class Log {
public:
  Log(QApplication *app) : m_content(File{app, "log.txt"}) {}
  ~Log() {}
  void info(QString msg);
  void warning(QString msg);
  void error(QString msg);
  QString logDirectory();

private:
  File m_content;
  void process(QString msg);
  const QString fileName = "log.txt";
};
