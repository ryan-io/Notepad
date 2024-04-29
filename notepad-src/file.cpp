#include "file.h"

File::File(QApplication *app) : m_application(app) {}

QString File::directory() {
  return m_application->applicationDirPath() + QDir::separator();
}

const QString &File::getContent() const {
  std::shared_lock<std::shared_mutex>(m_readMutex);
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
