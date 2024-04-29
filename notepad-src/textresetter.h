#include "fileresetter.h"
#include "logging.h"

#pragma once

class TextResetter : public FileResetter {
public:
  TextResetter(Log *logger) : m_logger(logger) {}
  ~TextResetter() override = default;

  // returns an IOResponse
  // isError will be set to true if cannot open, lock, or file is readonly
  // bad-reponse map for errors is "error"
  //        error will log a generic message -> should always be able to reset
  // good-reponse map:
  //      "ok" -> generic message stating reset was successful
  IOResponse reset(File *file) override;

private:
  Log *m_logger = nullptr;
};
