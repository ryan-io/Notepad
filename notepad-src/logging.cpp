#include "logging.h"
#include <QDebug>

void Log::Info(QString msg) { qInfo() << msg; }

void Log::Warning(QString msg) { qWarning() << msg; }

void Log::Error(QString msg) { qCritical() << msg; }
