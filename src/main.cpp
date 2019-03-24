#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "InputBuffer.h"
#include "MetaCommand.h"
#include "Statement.h"
#include "DataStructure.h"
#include "Table.h"

void prompt();

int main() {
  Table table;
  InputBuffer input;
  Statement statement;

  while (true) {
    prompt();
    input.read();

    const string& buffer = input.getBuffer();

    bool isMetaCommand = buffer[0] == '.';

    if (isMetaCommand) {
      switch (doMetaCommand(input)) {
        case (META_COMMAND_SUCCESS):
          continue;
        
        case (META_UNRECOGNIZED_COMMAND):
          cout << "Unrecognized command " << buffer << "." << endl;
          continue;
      }
    }

    switch (statement.prepareStatement(input)) {
      case (PREPARE_SUCCESS):
        break;

      case (PREPARE_SYNTAX_ERROR):
        cout << "Syntax error. Could not parse statement." << endl;
        continue;

      case (PREPARE_UNRECOGNIZED_STATEMENT):
        cout << "Unrecognized keyword at start of " << buffer << "." << endl;
        continue;
    }

    switch (table.executeStatement(statement)) {
      case (EXECUTE_SUCCESS):
        break;

      case (EXECUTE_TABLE_FULL):
        cout << "Cannot serialize row. Table is full." << endl;
        continue;        
    }
  }
  
  return 1;
}

void prompt() {
  cout << "db > ";
}
