#include "logging.h"
#include "notepad.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Log log{"log.txt", &a, OutputLevel::Console};

  qInfo() << "Logging to" << log.logName() << "to directory"
          << log.logDirectory();

  log.info("Logging started...");

  Notepad w{&a, &log};
  w.show();

  return a.exec();
}
