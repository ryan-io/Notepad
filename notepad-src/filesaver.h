#include "file.h"
#include "ioresponse.h"

#include <QString>

#pragma once

class FileSaver {
public:
  // saves the current file with respect to file.getFileName()
  virtual IOResponse save(File *file) = 0;

  // saves the log to the current working directory
  // this method invokes reset() if save was successful
  // returns false if save was unsuccessful
  virtual IOResponse save(File *file, QString fileName) = 0;

  // saves the log to a specific directory
  // this method invokes reset() if save was successful
  // returns false if save was unsuccessful
  virtual IOResponse save(File *file, QString fileName, QString path) = 0;

  virtual ~FileSaver() = default;
};
