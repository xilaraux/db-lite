#ifndef META_COMMAND_H
#define META_COMMAND_H

#include "InputBuffer.h"

enum MetaCommandResult {
  META_COMMAND_SUCCESS,
  META_UNRECOGNIZED_COMMAND
};

MetaCommandResult doMetaCommand(const InputBuffer& input) {
  const string buffer = input.getBuffer();

  if (buffer == ".exit") {
    exit(EXIT_SUCCESS);
  } else {
    return META_UNRECOGNIZED_COMMAND;
  }
}

#endif