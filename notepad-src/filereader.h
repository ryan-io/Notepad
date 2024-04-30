#include "ioresponse.h"

#include <QWidget>

#pragma once

class FileReader {
public:
  virtual IOResponse read(QWidget *parent, QString &filePath) = 0;
  virtual ~FileReader() = default;
};
