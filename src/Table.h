#ifndef TABLE_H
#define TABLE_H

#include <vector>
using std::vector;

#include "DataStructure.h"
#include "Statement.h"

enum ExecuteResult {
  EXECUTE_SUCCESS,
  EXECUTE_TABLE_FULL
};

class Table {
  public:
    ExecuteResult executeStatement(Statement&);

  private:
    static const uint32_t MAX_PAGES = 100;

    vector<Row> pages;

    void print_row(const Row&);
    ExecuteResult executeInsert(Row&);
    ExecuteResult executeSelect();
};

#endif
