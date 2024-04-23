#pragma once

#include <QObject>

#include "filecontent.h"

class Log {
public:
  Log() : m_content(FileContent{}) {}
  ~Log() {}
  void Info(QString msg);
  void Warning(QString msg);
  void Error(QString msg);

  enum class Level : qint8 { Info = 1 << 0, Warning = 1 << 1, Error = 1 << 2 };

private:
  FileContent m_content;
};
