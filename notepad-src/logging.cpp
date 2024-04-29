#include "logging.h"
#include "textsaver.h"
#include "textwriter.h"
#include <QDebug>
#include <thread>

void Log::info(QString msg) {
  process("INFO: " + msg);
  qInfo() << msg;
}

void Log::warning(QString msg) {
  process("WARNING: " + msg);
  qWarning() << msg;
}

void Log::error(QString msg) {
  process("ERROR: " + msg);
  qCritical() << msg;
}

QString Log::logDirectory() { return m_content.directory(); }

void Log::process(QString msg) {
  TextWriter tw{};
  tw.writeAppend(m_content, "Log - " + msg);

  TextSaver ts{m_content.directory()};
  ts.save(&m_content, fileName);
}
