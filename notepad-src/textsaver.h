#pragma once

#include "filesaver.h"
#include "logging.h"

class TextSaver : public FileSaver {
public:
  TextSaver(const QString &defaultDir) : m_defaultDir(defaultDir){};
  virtual ~TextSaver() = default;

  // FileSaver interface
  IOResponse save(File *file) override;
  IOResponse save(File *file, QString fileName) override;
  IOResponse save(File *file, QString fileName, QString path) override;

private:
  const QString m_defaultDir;
};
