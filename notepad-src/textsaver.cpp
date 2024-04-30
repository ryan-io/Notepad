#include "textsaver.h"
#include "constant.h"

#include <QLockFile>

IOResponse TextSaver::save(File *file, SaveFlag flag) {
  return save(file, file->getFileName(), m_defaultDir, flag);
}

IOResponse TextSaver::save(File *file, QString fileName, SaveFlag flag) {
  return save(file, fileName, m_defaultDir, flag);
}

void TextSaver::AppendData(QFile *output, File *file) {
  QByteArray data;
  data.append(
      file->getContent()
          .toLocal8Bit()); // change this at a later point in time if needed

  output->write(data);
  output->close();
}

IOResponse TextSaver::save(File *file, QString fileName, QString path,
                           SaveFlag flag) {
  QFile output(fileName);

  QLockFile lock(output.fileName() + LOCK_SUFFIX);
  lock.setStaleLockTime(STALE_LOCK_TIME);

  if (lock.tryLock()) {
    if (!output.open(flag)) {
      lock.unlock();
      QString fError = "Could not open file.";
      return IOResponse{true, {std::make_pair("error", fError)}};
    }
  } else {
    QString fError = "Error: Could not write to file " + fileName;
    // output some info from lock info (pid, host, application, etc.)
    return IOResponse{true, {std::make_pair("error", fError)}};
  }

  qInfo() << "Lock was obtained on " << output.fileName();
  AppendData(&output, file);
  lock.unlock();

  const QString okResponse = "File successfully saved.";
  return IOResponse{false, {std::make_pair("ok", okResponse)}};
}
