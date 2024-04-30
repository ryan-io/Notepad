#include "file.h"
#include "ioresponse.h"

#include <QString>

#pragma once

class FileSaver {
public:
  typedef QIODevice::OpenModeFlag SaveFlag;
  // saves the current file with respect to file.getFileName()
  virtual IOResponse save(File *file, SaveFlag flag) = 0;

  // saves the log to the current working directory
  // this method invokes reset() if save was successful
  // returns false if save was unsuccessful
  virtual IOResponse save(File *file, QString fileName, SaveFlag flag) = 0;

  // saves the log to a specific directory
  // this method invokes reset() if save was successful
  // returns false if save was unsuccessful
  virtual IOResponse save(File *file, QString fileName, QString path,
                          SaveFlag flag) = 0;

  virtual ~FileSaver() = default;
};
