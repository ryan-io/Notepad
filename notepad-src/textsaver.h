#pragma once

#include "filesaver.h"
#include "logging.h"

class TextSaver : public FileSaver {
public:
  TextSaver(const QString &defaultDir, Log *logger)
      : m_defaultDir(defaultDir), m_logger(logger){};
  virtual ~TextSaver() = default;

  // FileSaver interface
  IOResponse save(File *file, QString fileName) override;
  IOResponse save(File *file, QString fileName, QString path) override;

private:
  const QString m_defaultDir;
  Log *m_logger = nullptr;
};
