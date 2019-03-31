#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

#include <iostream>
using std::istream;

#include <string>
using std::string;

class InputBuffer {
  public:
    void read(istream&);
    const string& getBuffer() const;

  private:
    string buffer;
};

#endif
