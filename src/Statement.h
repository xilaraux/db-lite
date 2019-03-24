#ifndef STATEMENT_H
#define STATEMENT_H

#include "InputBuffer.h"
#include "DataStructure.h"

enum StatementType {
  STATEMENT_INSERT,
  STATEMENT_SELECT
};

enum PrepareResult {
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT,
  PREPARE_SYNTAX_ERROR
};

class Statement {
  public:
    Row& getRow();
    StatementType getType();
    PrepareResult prepareStatement(const InputBuffer&);
    
  private:
    Row insertRow;
    StatementType type;
};

#endif