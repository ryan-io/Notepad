#include "logging.h"
#include "textwriter.h"
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <thread>

QString Log::logDirectory() { return QDir::currentPath(); }

QString Log::logName() { return m_fileName; }

QString Log::time() { return QDateTime::currentDateTime().toString(); }

void Log::info(const QString &msg) { process(msg, Level::INFO); }

void Log::warning(const QString &msg) { process(msg, Level::WARNING); }

void Log::error(const QString &msg) { process(msg, Level::ERROR); }

// core method that handles prefixing the logs
// checks what bits are set in m_output and logs to appropriate source(s)
void Log::process(const QString &msg, Level level) {
  if (m_output & OutputLevel::None) {
    return;
  }

  if (m_output & OutputLevel::Console) {
    switch (level) {
    case Log::INFO:
      qInfo() << msg;
      break;
    case Log::WARNING:
      qWarning() << msg;
      break;
    case Log::ERROR:
      qCritical() << msg;
      break;
    }
  }

  if (m_output & OutputLevel::Text) {
    // write to text file
    /*
     *   TextWriter tw{};
tw.writeAppend(m_content, "Log - " + msg);

TextSaver ts{m_content.directory()};
ts.save(&m_content, fileName);
     */
  }
}

// Qt preprocessor macros for logging what OS the user is on
void Log::logOs() {
#ifdef Q_OS_LINUX
  qInfo() << "Running on Linux";
#endif

#ifdef Q_OS_WINDOWS
  qInfo() << "Runing on Windows";
#endif

#ifdef Q_OS_MAC
  qInfo() << "Runing on Mac";
#endif
}

void Log::logOutputTo() {
  if (m_output & OutputLevel::None)
    qInfo() << "Logging disabled";
  if (m_output & OutputLevel::Console)
    qInfo() << "Logging to console";
  if (m_output & OutputLevel::Text)
    qInfo() << "Logging to text file";
}

void Log::validateAndCreate(const QString &name) {
  if ((m_output & OutputLevel::Text) == 0)
    return;

  TextWriter tw{};
  auto response = tw.append(name, QDir::currentPath(), time());

  if (response.isError)
    qCritical() << response.message;
}
