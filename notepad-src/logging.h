#pragma once

#include <QDateTime>
#include <QObject>

#include "filecontent.h"

class Log {
public:
  Log(QApplication *app) : m_content(FileContent{app}) {}
  ~Log() {}
  void Info(QString msg);
  void Warning(QString msg);
  void Error(QString msg);

private:
  FileContent m_content;
  QString stamp() { return QDateTime::currentDateTime().toString() + ": "; }
  void process(QString msg);
  const QString fileName = "log.txt";
};
