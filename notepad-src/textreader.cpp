#include "textreader.h"

#include "constant.h"
#include <QFile>
#include <QFileDialog>
#include <QLockFile>
#include <QMessageBox>
#include <QString>

class OpenFilePrompt {
public:
  QFile Open(QWidget *owner) {
    auto fileName = QFileDialog::getOpenFileName(owner, PROMPT_WINDOW_NAME);
    return QFile(fileName);
  }

private:
  const QString PROMPT_WINDOW_NAME = "Open File";
};

// returns an IOResponse with the following characteristics
//      "error"-> if file path is empty
//      "error"-> if the file already has a mutual exlusion lock
//      "filepath"-> ok; gets the file path read
//      "content"-> ok; gets the content of the file read
IOResponse TextReader::read(QWidget *parent, QString &filePath) {
  if (filePath.isEmpty())
    return {true, FILE_PATH_EMPTY};

  QFile check(filePath);

  if (!check.open(QIODevice::ReadOnly)) {
    check.close();
    return {true, CANNOT_OPEN};
  }

  QTextStream str(&check);
  const QString content = str.readAll();
  check.close();

  return {false, content};
}
