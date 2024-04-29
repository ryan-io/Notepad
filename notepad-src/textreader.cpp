#include "textreader.h"

#include "constant.h"
#include <QFileDialog>
#include <QLockFile>
#include <QMessageBox>
#include <QString>

IOResponse TextReader::read(QWidget *parent) {
  QString filePath = QFileDialog::getOpenFileName(parent, "Open a file");

  if (filePath.isEmpty()) {
    const QString fError = "File path is empty";
    m_logger->error(fError);
    return IOResponse{true, {std::make_pair("error", fError)}};

    QFile file(filePath);
    QLockFile lock(file.fileName() + LOCK_SUFFIX);
    lock.setStaleLockTime(STALE_LOCK_TIME);

    if (!lock.tryLock(STALE_LOCK_TIME)) {
      const QString fError = "Could not lock file";
      m_logger->error(fError);
      return IOResponse{true, {std::make_pair("error", fError)}};
    }

    if (!file.open(QIODevice::ReadOnly)) {
      m_logger->error(file.errorString());
      return IOResponse{true, {std::make_pair("error", file.errorString())}};
    }

    QTextStream str(&file);
    const QString content = str.readAll();

    lock.unlock();
    file.close();

    std::unordered_map<std::string, QString> goodResponse =
        std::unordered_map<std::string, QString>{
            {std::make_pair("filepath", filePath)},
            {std::make_pair("content", content)}};

    return {false, goodResponse};
  };
}
