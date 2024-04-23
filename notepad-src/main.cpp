#include "logging.h"
#include "notepad.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Log log{&a};

  log.Info("Hola!");
  log.Warning("Hola!");
  log.Error("Hola!");
  Notepad w;
  w.show();

  return a.exec();
}
