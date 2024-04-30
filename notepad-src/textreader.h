#include "filereader.h"
#include "logging.h"

#pragma once

class TextReader : public FileReader {
public:
  TextReader(){};

  // returns an IOResponse
  // isError will be set to true if cannot open, lock, or file is readonly
  // bad-reponse map for errors is "error"
  // good-rponse map:
  //      "filepath" returns QString with file path
  //      "content" returns QString with read content
  IOResponse read(QWidget *parent, QString &filePath) override;
  ~TextReader() override = default;
};
