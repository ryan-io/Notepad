#include "textwriter.h"

IOResponse TextWriter::write(File &file, QString content) {
  const QString okOut = "Writing content to file object.";

  m_logger->info(okOut);

  // std::lock_guard<std::mutex> lock(m_writeLock);

  file.m_output.clear();
  file.m_output.append(content);
  file.m_output.append('\n');

  return {false, {std::make_pair("ok", okOut)}};
}

IOResponse TextWriter::writeAppend(File &file, QString content) {
  const QString okOut = "Appending content to file object.";

  // m_logger->info(okOut);

  // std::lock_guard<std::mutex> lock(m_writeLock);

  file.m_output.append(content);
  file.m_output.append('\n');

  return {false, {std::make_pair("ok", okOut)}};
}
