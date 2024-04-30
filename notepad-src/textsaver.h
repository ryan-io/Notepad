#pragma once

#include "filesaver.h"
#include "logging.h"

class TextSaver : public FileSaver {
public:
  TextSaver(const QString &defaultDir) : m_defaultDir(defaultDir){};
  virtual ~TextSaver() = default;

  // FileSaver interface
  IOResponse save(File *file, SaveFlag flag = QIODevice::Append) override;
  IOResponse save(File *file, QString fileName,
                  SaveFlag flag = QIODevice::Append) override;
  IOResponse save(File *file, QString fileName, QString path,
                  SaveFlag flag = QIODevice::Append) override;

  void AppendData();

private:
  void AppendData(QFile *output, File *file);
  const QString m_defaultDir;
};
