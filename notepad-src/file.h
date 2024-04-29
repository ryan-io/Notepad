#include "content.h"

#include <QApplication>
#include <QDir>
#include <mutex>
#include <shared_mutex>

#pragma once

// characterizes a simple text string file
class File : public Content {
public:
  File(QApplication *app, QString fileName);
  ~File() = default;

  // returns the application directory where logs are being written to
  QString directory();

  QString getFileName() const;

  QString setFileName(QString &newName);

  // returns a constant reference to m_output
  QString &getContent() override;

  // sets the internal QString field
  void setContent(const QString &newContent) override;

  // appends a QString to the end of m_output;
  void appendContent(const QString &appendContent) override;

private:
  QString m_output{};
  QString m_fileName{};
  QApplication *m_application = nullptr;
  std::mutex m_writeMutex{};
  std::shared_mutex m_readMutex;
  friend class TextResetter;
  friend class TextWriter;
  friend class Log;
};
