#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

#include <string>
using std::string;

class InputBuffer {
  public:
    void read();
    const string& getBuffer() const;

  private:
    string buffer;
};

#endif