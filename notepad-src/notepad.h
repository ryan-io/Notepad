#pragma once

#include <QMainWindow>

#include "filecontent.h"
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

private:
  Ui::Notepad *ui;
  Log *m_logger;
  FileContent m_file;
  const QString LOCK_SUFFIX = "_lock";
  static constexpr int STALE_LOCK_TIME = 3000;
};
