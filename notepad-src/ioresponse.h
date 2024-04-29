#include <QString>
#include <unordered_map>

#pragma once

struct IOResponse {
  bool isError;
  std::unordered_map<std::string, QString> response;
};
