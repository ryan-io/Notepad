#pragma once
#include <QFile>

class ReadWriteSave {
public:
  virtual void write(QString content) = 0;
  virtual bool save(QString fileName) = 0;
  virtual bool save(QString fileName, QString path) = 0;
  virtual void reset() = 0;
  virtual ~ReadWriteSave() = default;
};
