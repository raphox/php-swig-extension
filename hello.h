#ifndef HELLO_H_
#define HELLO_H_

class Hello
{
private:
  bool formal;

public:
  const char* greeting();
  void setFormal(bool f);
  bool getFormal();
};

#endif /*HELLO_H_*/
