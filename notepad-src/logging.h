#pragma once

#include "file.h"

#include <QApplication>
#include <QDateTime>
#include <QObject>

// bitwise 'or' these together to log to multiple outputs
class OutputLevel {
public:
  static constexpr int_fast8_t None = 0x1;
  static constexpr int_fast8_t Console = 0x2;
  static constexpr int_fast8_t Text = 0x3;
};

class Log {
public:
  enum Level { INFO = 1 << 0, WARNING = 1 << 1, ERROR = 1 << 2 };

  Log(const QString &name, QApplication *app, const int_fast8_t output = 0)
      : m_content(File{app, name}), m_output(output) {}

  ~Log() {}

  void info(const QString &msg);
  void warning(const QString &msg);
  void error(const QString &msg);
  QString logDirectory();
  QString logName();

private:
  int_fast8_t m_output;
  File m_content;
  void process(const QString &msg, Level level);
};
