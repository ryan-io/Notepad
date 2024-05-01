#pragma once

#include <QMainWindow>

#include "file.h"
#include "logging.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Notepad;
}
QT_END_NAMESPACE

class Notepad : public QMainWindow {
  Q_OBJECT

public:
  Notepad(QApplication *app, Log *logger, QWidget *parent = nullptr);
  ~Notepad();

private slots:
  void on_actionNew_triggered();

  void on_actionOpen_triggered();

  void on_actionSave_triggered();

  void on_actionSave_As_triggered();

private:
  Ui::Notepad *ui;
  Log *m_logger;
  File m_file;
};
