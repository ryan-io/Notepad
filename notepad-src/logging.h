#pragma once

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
      : m_output(output), m_fileName(name) {
    logOs();
    logOutputTo();
    validateAndCreate(name);
  }

  ~Log() {}

  void info(const QString &msg);
  void warning(const QString &msg);
  void error(const QString &msg);
  QString logDirectory();
  QString logName();
  QString time();

private:
  int_fast8_t m_output{0};
  QString m_fileName{""};

  void process(const QString &msg, Level level);
  void logOutputTo();
  void validateAndCreate(const QString &name);
  static void logOs();
};
