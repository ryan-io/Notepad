#include "file.h"
#include "ioresponse.h"

#include <QString>

#pragma once

class FileWriter {
public:
  // writes to the internal QString buffer
  virtual IOResponse write(File &file, QString content) = 0;
  virtual IOResponse writeAppend(File &file, QString content) = 0;

  virtual ~FileWriter() = default;
};
