#include "notepad.h"
#include "./ui_notepad.h"

Notepad::Notepad(QWidget *parent) : QMainWindow(parent), ui(new Ui::Notepad) {
  ui->setupUi(this);
}

Notepad::~Notepad() { delete ui; }

void Notepad::onNewDocument() {
  m_currentFile.clear(); // clears string; null

  // set the text in the editor to an empty string
  ui->textEditor->setText(QString{});
}
