#include "notepad.h"
#include "./ui_notepad.h"
#include "QFileDialog"
#include "QLockFile"
#include "QMessageBox"
#include "QTextStream"

Notepad::Notepad(QApplication *app, Log *logger, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Notepad), m_file(app), m_logger(logger) {
  ui->setupUi(this);
}

Notepad::~Notepad() { delete ui; }

void Notepad::on_actionNew_triggered() {
  if (m_logger) {
    m_logger->info("onNewDocument invoked");
    m_logger->info("resetting text editor text");
    m_logger->info("resetting m_file");
  } else {
    qWarning() << "No logger supplied";
  }

  m_file.reset(); // clears string; null

  // set the text in the editor to an empty string
  ui->textEditor->setText(m_file.getContent());
}

void Notepad::on_actionOpen_triggered() {
  QString fileName = QFileDialog::getOpenFileName(this, "Open a file");

  if (fileName.isEmpty()) {
    m_logger->warning("File name is empty");
    return;
  }

  m_logger->info("Attempting to open file " + fileName);
  QFile file(fileName);

  QLockFile lock(file.fileName() + LOCK_SUFFIX);
  lock.setStaleLockTime(STALE_LOCK_TIME);

  if (!lock.tryLock(STALE_LOCK_TIME)) {
    m_logger->error("Could not lock file");
    return;
  }

  if (!file.open(QIODevice::ReadOnly)) {
    m_logger->error(file.errorString());
    QMessageBox::warning(this, "Warning",
                         "Could not open file - " + file.errorString());
    return;
  }

  setWindowTitle(fileName);
  QTextStream str(&file);
  QString content = str.readAll();

  m_file.write(content);
  ui->textEditor->setText(m_file.getContent());

  lock.unlock();
  file.close();
}

void Notepad::on_actionSave_triggered() {}
