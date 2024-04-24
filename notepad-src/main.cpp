#include "logging.h"
#include "notepad.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Log log{&a};
  qInfo() << "Logging to " << log.logDirectory();
  log.info("Logging stated");
  Notepad w{&a, &log};
  w.show();

  return a.exec();
}
