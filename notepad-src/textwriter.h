#include "filewriter.h"
#include "logging.h"
#include <mutex>

#pragma once

class TextWriter : public FileWriter {
public:
  TextWriter(){};
  ~TextWriter() override = default;

  // FileWriter interface
  IOResponse write(File &file, QString content) override;
  IOResponse writeAppend(File &file, QString content) override;

private:
  std::mutex m_writeLock;
};
