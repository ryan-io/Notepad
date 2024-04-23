#include "filecontent.h"
#include <QFile>>

FileContent::FileContent() {}

void FileContent::Write(QString content) {
  m_output.append('\n');
  m_output.append(content);
}

bool FileContent::Save() {}

bool FileContent::Save(QString path) {}

void FileContent::Reset() {}
