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
IOResponse TextReader::read(QWidget *parent, QString &filePath) {
  if (filePath.isEmpty()) {
    const QString fError = "File path is empty";
    return IOResponse{true, {std::make_pair("error", fError)}};
  };

  QFile file(filePath);

  if (!file.open(QIODevice::ReadOnly)) {
    file.close();
    return IOResponse{true, {std::make_pair("error", file.errorString())}};
  }

  QTextStream str(&file);
  const QString content = str.readAll();

  file.close();

  std::unordered_map<std::string, QString> goodResponse =
      std::unordered_map<std::string, QString>{
          {std::make_pair("filepath", filePath)},
          {std::make_pair("content", content)}};

  return {false, goodResponse};
}
