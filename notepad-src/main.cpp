#include "logging.h"
#include "notepad.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Log log{&a};

  Notepad w;
  w.show();

  return a.exec();
}
