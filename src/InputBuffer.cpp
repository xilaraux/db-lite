#include <iostream>
using std::istream;

#include <string>
using std::getline;

#include "InputBuffer.h"

void InputBuffer::read(istream& string_stream) {
  getline(string_stream, this->buffer);
}

const string& InputBuffer::getBuffer() const {
  return this->buffer;
}
