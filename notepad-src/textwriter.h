#include "filewriter.h"
#include "logging.h"
#include <mutex>

#pragma once

class TextWriter : public FileWriter {
public:
  TextWriter(){};
  ~TextWriter() override = default;

  // FileWriter interface
  IOResponse write(QFile &file, QString content) override;
  IOResponse writeAppend(QFile &file, QString content) override;

private:
  std::mutex m_writeLock;
};
