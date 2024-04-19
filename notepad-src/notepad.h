#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Notepad;
}
QT_END_NAMESPACE

class Notepad : public QMainWindow {
  Q_OBJECT

public:
  Notepad(QWidget *parent = nullptr);
  ~Notepad();

private slots:
  void onNewDocument();

private:
  Ui::Notepad *ui;
  QString m_currentFile;
};
