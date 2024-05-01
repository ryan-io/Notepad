#include "notepad.h"
#include "./ui_notepad.h"
#include "QFileDialog"
#include "QLockFile"
#include "QMessageBox"
#include "QTextStream"
#include "textreader.h"
#include "textresetter.h"
#include "textsaver.h"
#include "textwriter.h"

Notepad::Notepad(QApplication *app, Log *logger, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Notepad), m_file(app, "notepad-log.txt"),
      m_logger(logger) {
  ui->setupUi(this);
}

Notepad::~Notepad() { delete ui; }

void Notepad::on_actionNew_triggered() {
  if (m_logger) {
    m_logger->info("onNewDocument invoked");
  } else {
    qWarning() << "No logger supplied";
  }

  TextResetter tr{};
  // clears string; invokes QString.clear()
  auto resetResponse = tr.reset(&m_file);

  if (m_logger) {
    if (resetResponse.isError)
      m_logger->error(resetResponse.response["error"]);
    else
      m_logger->info(resetResponse.response["ok"]);
  }

  // set the text in the editor to an empty string
  ui->textEditor->setText(m_file.getContent());
}

void Notepad::on_actionOpen_triggered() {
  QString filePath = QFileDialog::getOpenFileName(this, "Open a file");
  TextReader reader{};

  m_logger->info("onActionOpen invoked");
  auto readResponse = reader.read(this, filePath);

  if (readResponse.isError) {
    m_logger->error(readResponse.response["error"]);
    QMessageBox::warning(this, "Warning", readResponse.response["error"]);
    return;
  }

  m_logger->info("File read: " + readResponse.response["filepath"]);
  m_logger->info("Setting in-memory file content");

  TextWriter tw{};
  // best practice to let the writer run any pre-processing
  tw.write(m_file, readResponse.response["content"]);

  ui->textEditor->setText(readResponse.response["content"]);
  m_file.setFileName(readResponse.response["filepath"]);
  setWindowTitle(readResponse.response["filepath"]);
}

void Notepad::on_actionSave_triggered() {
  m_logger->info("onActionSaved invoked");

  TextSaver ts{m_file.directory()};

  // if (m_file.getFileName ().isEmpty ()) {
  auto newName = QFileDialog::getSaveFileName(this, "Save");
  //}

  qInfo() << "Saving as " << newName;
  auto response = ts.save(&m_file, newName, QIODevice::WriteOnly);

  if (response.isError)
    m_logger->error(response.response["error"]);
  else
    m_logger->info(response.response["ok"]);
}

void Notepad::on_actionSave_As_triggered() {}
