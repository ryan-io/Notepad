#include "textresetter.h"

// returns an IOResponse
// isError will be set to true if cannot open, lock, or file is readonly
// bad-reponse map for errors is "error"
//        error will log a generic message -> should always be able to reset
// good-reponse map:
//      "ok" -> generic message stating reset was successful
IOResponse TextResetter::reset(File *file) {

  file->m_output.clear();
  return {false, {std::make_pair("ok", "File has been cleared")}};
}
