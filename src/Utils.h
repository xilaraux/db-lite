#ifndef UTILS_H
#define UTILS_H

#include <string>
using std::string;

#include "DataStructure.h"

int parseInsertStatement(const string& target, Row& insertRow);

#endif

