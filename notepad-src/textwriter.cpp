#include "textwriter.h"

#include <QDir>

IOResponse TextWriter::WriteTo(const QString &name, const QString &directory,
                               const QString &content,
                               QIODeviceBase::OpenModeFlag flag) {
  auto emptyShared = std::make_shared<QFile>();

  if (name.isEmpty())
    return {true, FILE_NAME_EMPTY, emptyShared};

  if (directory.isEmpty())
    return {true, DIRECTORY_EMPTY, emptyShared};

  if (content.isEmpty())
    return {true, CONTENT_BLANK, emptyShared};

  auto check = std::make_shared<QFile>(directory + QDir::separator() + name);

  if (!check->open(flag)) {
    check->close();
    return {true, CANNOT_OPEN, emptyShared};
  }

  QByteArray data{};

  data.append(content.toUtf8() + '\n');
  check->write(data);
  check->close();

  return {false, WroteSuccessfuly(*check), check};
}

IOResponse TextWriter::write(const QString &name, const QString &directory,
                             const QString &content) {
  return WriteTo(name, directory, content, QIODevice::WriteOnly);
}

IOResponse TextWriter::append(const QString &name, const QString &directory,
                              const QString &content) {
  return WriteTo(name, directory, content, QIODevice::Append);
}
