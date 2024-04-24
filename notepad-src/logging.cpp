#include "logging.h"
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

QString Log::logDirectory() { return m_content.defaultDirectory(); }

void Log::process(QString msg) {
  m_content.write(stamp() + msg);
  m_content.save(fileName);
}
