#include "logging.h"
#include "textsaver.h"
#include "textwriter.h"
#include <QDebug>
#include <thread>

QString Log::logDirectory() { return m_content.directory(); }

QString Log::logName() { return m_content.getFileName(); }

void Log::info(const QString &msg) { process(msg, Level::INFO); }

void Log::warning(const QString &msg) { process(msg, Level::WARNING); }

void Log::error(const QString &msg) { process(msg, Level::ERROR); }

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
