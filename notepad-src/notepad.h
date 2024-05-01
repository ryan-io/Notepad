#pragma once

#include <QFile>
#include <QFileInfo>
#include <QMainWindow>

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

  void on_actionFont_triggered();

  void on_actionFont_Size_triggered();

private:
  void Save(QFileInfo &info);

  Ui::Notepad *ui;
  Log *m_logger;
  QString m_openedFile;
};
