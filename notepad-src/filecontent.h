#pragma once
#include <QDateTime>
#include <QFile>
#include <QObject>

class FileContent {
public:
  FileContent();
  void write(QString content);
  bool save();
  bool save(QString path);
  void reset();

private:
  bool stamp() { auto now = QDateTime::currentSecsSinceEpoch() return 1; }

  QString m_output;
};
