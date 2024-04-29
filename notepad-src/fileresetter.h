#include "file.h"
#include "ioresponse.h"

#pragma once

// probably overkill... leave it in anyways
// there have been a handful of instances in the past where a file needed
//      to be formatted before being in an "acceptable" state
class FileResetter {
public:
  virtual IOResponse reset(File *file) = 0;
  virtual ~FileResetter() = default;
};
