#include <iostream>
using std::cout;
using std::endl;

#include "Table.h"

#include "Statement.h"
#include "DataStructure.h"

// PUBLIC
ExecuteResult Table::executeStatement(Statement& statement) {
  switch (statement.getType()) {
    case (STATEMENT_INSERT):
      return this->executeInsert(statement.getRow());

    case (STATEMENT_SELECT):
      return this->executeSelect();
  }
}

// PRIVATE
ExecuteResult Table::executeInsert(Row& rowToInsert) {
  if (this->pages.size() >= Table::MAX_PAGES) {
    return EXECUTE_TABLE_FULL;
  }

  this->pages.push_back(rowToInsert);

  return EXECUTE_SUCCESS;
}

ExecuteResult Table::executeSelect() {
  for (auto row : this->pages) {
    print_row(row);
  }

  return EXECUTE_SUCCESS;
}

void Table::print_row(const Row& row) {
  cout << '(' << row.id << ", " << row.username << ", " << row.email << ')' << endl;
}
