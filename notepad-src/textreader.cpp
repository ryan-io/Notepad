#include "textreader.h"

#include "constant.h"
#include <QFileDialog>
#include <QLockFile>
#include <QMessageBox>
#include <QString>

// returns an IOResponse with the following characteristics
//      "error"-> if file path is empty
//      "error"-> if the file already has a mutual exlusion lock
//      "filepath"-> ok; gets the file path read
//      "content"-> ok; gets the content of the file read
IOResponse TextReader::read(QWidget *parent) {
  QString filePath = QFileDialog::getOpenFileName(parent, "Open a file");

  if (filePath.isEmpty()) {
    const QString fError = "File path is empty";
    return IOResponse{true, {std::make_pair("error", fError)}};
  };

  QFile file(filePath);
  QLockFile lock(file.fileName() + LOCK_SUFFIX);
  lock.setStaleLockTime(STALE_LOCK_TIME);

  if (!lock.tryLock(STALE_LOCK_TIME)) {
    const QString fError = "Could not lock file";
    return IOResponse{true, {std::make_pair("error", fError)}};
  }

  if (!file.open(QIODevice::ReadOnly)) {
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
}
