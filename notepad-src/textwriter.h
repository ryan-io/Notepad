#include "filewriter.h"
#include "logging.h"
#include <mutex>

#pragma once

class TextWriter : public FileWriter {
public:
  TextWriter(Log *logger) : m_logger(logger){};
  ~TextWriter() override = default;

  // FileWriter interface
  IOResponse write(File &file, QString content) override;
  IOResponse writeAppend(File &file, QString content) override;

private:
  Log *m_logger = nullptr;
  std::mutex m_writeLock;
};
