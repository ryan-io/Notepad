#pragma once

#include <QDateTime>
#include <QObject>

#include "filecontent.h"

class Log {
public:
  Log(QApplication *app) : m_content(FileContent{app}) {}
  ~Log() {}
  void info(QString msg);
  void warning(QString msg);
  void error(QString msg);
  QString logDirectory();

private:
  FileContent m_content;
  QString stamp() { return QDateTime::currentDateTime().toString() + ": "; }
  void process(QString msg);
  const QString fileName = "log.txt";
};
