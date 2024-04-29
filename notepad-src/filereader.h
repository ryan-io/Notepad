#include "ioresponse.h"

#include <QWidget>

#pragma once

class FileReader {
public:
  virtual IOResponse read(QWidget *parent) = 0;
  virtual ~FileReader() = default;
};
