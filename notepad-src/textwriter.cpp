#include "textwriter.h"

#include <QDir>

IOResponse TextWriter::WriteTo(const QString &name, const QString &directory,
                               const QString &content,
                               QIODeviceBase::OpenModeFlag flag) {
  if (name.isEmpty())
    return {true, FILE_NAME_EMPTY};

  if (directory.isEmpty())
    return {true, DIRECTORY_EMPTY};

  if (content.isEmpty())
    return {true, CONTENT_BLANK};

  QFile check(directory + QDir::separator() + name);

  if (!check.open(flag)) {
    check.close();
    return {true, CANNOT_OPEN};
  }

  QByteArray data{};

  data.append(content.toUtf8() + '\n');
  check.write(data);
  check.close();

  return {false, WroteSuccessfuly(check)};
}

IOResponse TextWriter::write(const QString &name, const QString &directory,
                             const QString &content) {
  return WriteTo(name, directory, content, QIODevice::WriteOnly);
}

IOResponse TextWriter::append(const QString &name, const QString &directory,
                              const QString &content) {
  return WriteTo(name, directory, content, QIODevice::Append);
}
