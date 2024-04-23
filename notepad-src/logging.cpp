#include "logging.h"
#include <QDebug>
#include <thread>

void Log::Info(QString msg) {
  process("INFO: " + msg);
  qInfo() << msg;
}

void Log::Warning(QString msg) {
  process("WARNING: " + msg);
  qWarning() << msg;
}

void Log::Error(QString msg) {
  process("ERROR: " + msg);
  qCritical() << msg;
}

void Log::process(QString msg) {
  qInfo() << "Writing to " << m_content.defaultDirectory();

  m_content.write(msg);
  m_content.save(fileName);
}
