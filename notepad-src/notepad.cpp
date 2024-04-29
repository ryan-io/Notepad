#include "notepad.h"
#include "./ui_notepad.h"
#include "QFileDialog"
#include "QLockFile"
#include "QMessageBox"
#include "QTextStream"
#include "textreader.h"
#include "textresetter.h"

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

  TextResetter tr{m_logger};
  // clears string; invokes QString.clear()
  tr.reset(&m_file);

  // set the text in the editor to an empty string
  ui->textEditor->setText(m_file.getContent());
}

void Notepad::on_actionOpen_triggered() {
  TextReader reader{m_logger};
  auto readResponse = reader.read(this);

  if (readResponse.isError) {
    QMessageBox::warning(this, "Warning", readResponse.response["error"]);
    return;
  }

  // m_file.setContent(readResponse.response["content"]); // you can do this,
  // best practice to let the writer run any pre-processing
  ui->textEditor->setText(readResponse.response["content"]);
  setWindowTitle(readResponse.response["filepath"]);
}

void Notepad::on_actionSave_triggered() {}
