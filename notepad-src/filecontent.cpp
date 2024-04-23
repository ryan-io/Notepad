#include "filecontent.h"
#include "QFile"

FileContent::FileContent(QApplication *app) : m_application(app) {}

FileContent::~FileContent() = default;

void FileContent::write(QString content) {
  std::lock_guard<std::mutex> lock(m_write);
  m_output.append(content);
  m_output.append('\n');
}

// see bool FileContent::save(QString fileName, QString path)
// passes 'path' as m_application->applicationDirPath()
bool FileContent::save(QString fileName) {
  return save(fileName, m_application->applicationDirPath());
}

// creates a QFile, attempts to open and returns false if cannot open
// creates a QByteArray from output buffer with 8bit enocding (calls
// toLocal8Bit()) output buffer is then appended to this QByteArray
bool FileContent::save(QString fileName, QString path) {
  QFile output(path + '/' + fileName);

  std::lock_guard<std::mutex> lock(m_read);
  if (!output.open(QIODevice::Append))
    return false;

  QByteArray data;
  data.append(
      m_output.toLocal8Bit()); // change this at a later point in time if needed

  output.write(data);
  output.close();

  reset();

  return true;
}

// creates a new instance of QString on the stack
void FileContent::reset() { m_output = QString{}; }
