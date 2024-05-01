#include "file.h"
#include <shared_mutex>

File::File(QApplication *app, const QString fileName)
    : m_application(app), m_fileName(fileName) {}

QString File::directory() {
  return m_application->applicationDirPath() + QDir::separator();
}

QString File::getFileName() const { return m_fileName; }

void File::setFileName(const QString &newName) { m_fileName = newName; }

const QString &File::getContent() const { return m_output; }

void File::setContent(const QString &newContent) {
  m_output = newContent;
  m_output.append('\n');
}

void File::appendContent(const QString &appendContent) {
  m_output.append(appendContent);
  m_output.append('\n');
}
