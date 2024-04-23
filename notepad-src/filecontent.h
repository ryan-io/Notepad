#pragma once
#include "readwritesave.h"
#include <QApplication>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QObject>
#include <mutex>

class FileContent : public ReadWriteSave {
public:
  FileContent(QApplication *app);
  ~FileContent() override;

  // returns the application directory where logs are being written to
  QString defaultDirectory() {
    return m_application->applicationDirPath() + QDir::separator();
  }

  // writes to the internal QString buffer
  void write(QString content) override;

  // saves the log to the current working directory
  // this method invokes reset() if save was successful
  // returns false if save was unsuccessful
  bool save(QString fileName) override;

  // saves the log to a specific directory
  // this method invokes reset() if save was successful
  // returns false if save was unsuccessful
  bool save(QString fileName, QString path) override;

  // resets the output to be writen to the log
  void reset() override;

private:
  QString m_output;
  QApplication *m_application;
  std::mutex m_write{};
  std::mutex m_read{};

  constexpr static qint16 STATLE_LOCK_TIME_MILLISECONDS = 15000;
};
