#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstdio>

#include "InputBuffer.h"
#include "Statement.h"

#include "Utils.h"

StatementType Statement::getType() {
  return this->type;
}

Row& Statement::getRow() {
  return this->insertRow;
}

PrepareResult Statement::prepareStatement(const InputBuffer& input) {
  const string& buffer = input.getBuffer();

  if (buffer.compare(0, 6, "insert") == 0) {
    this->type = STATEMENT_INSERT;

    int argsAssigned = parseInsertStatement(buffer, this->insertRow);

    if (argsAssigned < 3) {
      return PREPARE_SYNTAX_ERROR;
    }

    return PREPARE_SUCCESS;
  }

  if (buffer.compare("select") == 0) {
    this->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}
