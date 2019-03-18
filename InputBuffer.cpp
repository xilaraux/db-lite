#include <iostream>
using std::cin;
using std::endl;
using std::cout;

#include <string>
using std::getline;

#include "InputBuffer.h"

void InputBuffer::read() {
  getline(cin, this->buffer);
}

const string& InputBuffer::getBuffer() const {
  return this->buffer;
}
