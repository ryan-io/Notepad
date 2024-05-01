#include "filewriter.h"
#include "logging.h"
#include <mutex>

#pragma once

class TextWriter : public FileWriter {
public:
  TextWriter(){};
  ~TextWriter() override = default;

  // returns IOResponse with the following pairs
  //    IOResponse::Ok ->
  IOResponse write(const QString &fileName, const QString &directory,
                   const QString &content) override;

  IOResponse append(const QString &fileName, const QString &directory,
                    const QString &content) override;

private:
  IOResponse WriteTo(const QString &name, const QString &directory,
                     const QString &content, QIODevice::OpenModeFlag flag);

  const QString WroteSuccessfuly(const QFile &file) {
    return "Succesfully wrote to " + file.fileName();
  }

  const QString CANNOT_OPEN =
      "File cannot be opened. Possible locked by another process thread.";

  const QString CONTENT_BLANK = "No content was passed to the writer.";

  const QString FILE_NAME_EMPTY = "No file name was provided.";

  const QString DIRECTORY_EMPTY = "No directory was provided.";
};
