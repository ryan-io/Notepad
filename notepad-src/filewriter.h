#include "ioresponse.h"

#include <QFile>
#include <QString>

#pragma once

class FileWriter {
public:
  // writes and saves content to a file
  virtual IOResponse write(const QString &fileName, const QString &directory,
                           const QString &content) = 0;

  // appens and saves contnet to a file
  virtual IOResponse append(const QString &fileName,
                                 const QString &directory,
                                 const QString &content) = 0;

  virtual ~FileWriter() = default;
};
