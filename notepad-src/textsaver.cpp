#include "textsaver.h"
#include "constant.h"

#include <QLockFile>

IOResponse TextSaver::save(File *file, QString fileName) {
  return save(file, fileName, m_defaultDir);
}

IOResponse TextSaver::save(File *file, QString fileName, QString path) {
  QFile output(path + '/' + fileName);

  QLockFile lock(output.fileName() + LOCK_SUFFIX);
  lock.setStaleLockTime(STALE_LOCK_TIME);

  if (lock.tryLock()) {
    if (!output.open(QIODevice::Append)) {
      lock.unlock();
      QString fError = "Could not open file.";
      m_logger->error(fError);
      return IOResponse{true, {std::make_pair("error", fError)}};
    }

    QByteArray data;
    data.append(
        file->getContent()
            .toLocal8Bit()); // change this at a later point in time if needed

    output.write(data);
    output.close();
  } else {
    QString fError = "Error: Could not write to file " + fileName;
    m_logger->error(fError);
    // output some info from lock info (pid, host, application, etc.)
    return IOResponse{true, {std::make_pair("error", fError)}};
  }

  lock.unlock();

  const QString okResponse = "File successfully saved.";
  return IOResponse{false, {std::make_pair("ok", okResponse)}};
}
