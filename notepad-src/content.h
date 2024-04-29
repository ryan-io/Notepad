#include <QString>

#pragma once

class Content {
public:
  virtual const QString &getContent() const = 0;
  virtual void setContent(const QString &newContent) = 0;
  virtual void appendContent(const QString &appendContent) = 0;
  ~Content() = default;
};
