#include "notepad.h"
#include "./ui_notepad.h"
#include "QFileDialog"
#include "QLockFile"
#include "QMessageBox"
#include "QTextStream"
#include "textreader.h"
#include "textwriter.h"
#include <QFontDialog>

Notepad::Notepad(QApplication *app, Log *logger, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Notepad), m_logger(logger) {
  ui->setupUi(this);
}

Notepad::~Notepad() { delete ui; }

void Notepad::Save(QFileInfo &info) {
  TextWriter tw{};
  auto response =
      tw.write(info.fileName(), info.path(), ui->textEditor->toPlainText());

  setWindowTitle(info.fileName());

  if (response.error())
    m_logger->error(response.message());
  else
    m_logger->info(response.message());
}

void Notepad::on_actionNew_triggered() {
  m_logger->info("New signal triggered.");
  ui->textEditor->setText("");
  m_openedFile = "";
  setWindowTitle("unnamed");
}

void Notepad::on_actionOpen_triggered() {
  m_logger->info("Open signal triggered.");

  QString filePath = QFileDialog::getOpenFileName(this, "Open a file");
  TextReader reader{};
  auto response = reader.read(this, filePath);

  if (response.error()) {
    m_logger->error(response.message());
    return;
  }

  m_logger->info("Opened file at: " + response.file().fileName());
  m_logger->info("Setting text for ui-notepad.");
  ui->textEditor->setText(response.message());
  m_openedFile = response.file().fileName();

  QFileInfo info(response.file().fileName());
  setWindowTitle(info.fileName());
}

void Notepad::on_actionSave_triggered() {
  m_logger->info("Save signal triggered.");

  QString saveFileName{};

  if (m_openedFile.isEmpty()) {
    saveFileName = QFileDialog::getSaveFileName(this);
    m_openedFile = saveFileName;
  } else {
    saveFileName = m_openedFile;
  }

  if (saveFileName.isEmpty())
    return;

  auto info = QFileInfo(saveFileName);
  Save(info);
}

void Notepad::on_actionSave_As_triggered() {
  m_logger->info("Save-as signal triggered.");

  auto saveFileName = QFileDialog::getSaveFileName(this);

  if (saveFileName.isEmpty()) {
    m_logger->info("No file selected after save-as command invoked.");
    return;
  }
  m_openedFile = saveFileName;

  auto info = QFileInfo(saveFileName);
  Save(info);
}

void Notepad::on_actionFont_triggered() {
  bool fontSelected;
  QFont font = QFontDialog::getFont(&fontSelected, this);

  if (fontSelected)
    ui->textEditor->setFont(font);
}

void Notepad::on_actionFont_Size_triggered() {
  QTextCursor cursor = ui->textEditor->textCursor();
  ui->textEditor->selectAll();
  ui->textEditor->setFontPointSize(16);
  ui->textEditor->setTextCursor(cursor);
}
