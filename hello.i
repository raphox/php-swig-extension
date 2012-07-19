%module MyModule
%{
#include "hello.h"
%}

class Hello {
private:
  bool formal;
public:
  const char* greeting();
  void setFormal(bool f);
  bool getFormal();
};
