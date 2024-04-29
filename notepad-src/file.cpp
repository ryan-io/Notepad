#include "file.h"
#include <shared_mutex>

File::File(QApplication *app, QString fileName) : m_application(app) {}

QString File::directory() {
  return m_application->applicationDirPath() + QDir::separator();
}

QString File::getFileName() const { return m_fileName; }

QString File::setFileName(QString &newName) { m_fileName = newName; }

QString &File::getContent() {
  std::shared_lock<std::shared_mutex> l(m_readMutex);
  return m_output;
}

void File::setContent(const QString &newContent) {
  std::lock_guard<std::mutex> lock(m_writeMutex);
  m_output = newContent;
  m_output.append('\n');
}

void File::appendContent(const QString &appendContent) {
  std::lock_guard<std::mutex> lock(m_writeMutex);
  m_output.append(appendContent);
  m_output.append('\n');
}
