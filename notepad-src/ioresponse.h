#include <QDebug>
#include <QFile>
#include <QString>
#include <unordered_map>

#pragma once

class IOResponse final {
public:
  IOResponse(bool isError, const QString &message, std::shared_ptr<QFile> file)
      : m_isError(isError), m_message(message),
        m_file(std::shared_ptr<QFile>(file)) {}

  bool error() { return m_isError; }
  QString message() { return m_message; }
  const QFile &file() { return *m_file.get(); }

private:
  bool m_isError;
  QString m_message;
  std::shared_ptr<QFile> m_file;
};
