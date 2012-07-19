#include "hello.h"
#include <iostream>
using namespace std;

const char* Hello::greeting()
{
  if (formal)
    return "Hello, nice to meet you!";
  else 
    return "What's up?";
}

void Hello::setFormal(bool f)
{
  formal = f;
}

bool Hello::getFormal()
{
  return formal;
}
