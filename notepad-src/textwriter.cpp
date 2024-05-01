#include "textwriter.h"

IOResponse TextWriter::write(QFile &file, QString content) {
  const QString okOut = "Writing content to file object.";
  // std::lock_guard<std::mutex> lock(m_writeLock);

  //  file.m_output.clear();
  //  file.m_output.append(content);
  //  file.m_output.append('\n');

  return {false, {std::make_pair("ok", okOut)}};
}

IOResponse TextWriter::writeAppend(QFile &file, QString content) {
  const QString okOut = "Appending content to file object.";

  // std::lock_guard<std::mutex> lock(m_writeLock);

  //  file.m_output.append(content);
  //  file.m_output.append('\n');

  return {false, {std::make_pair("ok", okOut)}};
}
