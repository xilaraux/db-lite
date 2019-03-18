#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using std::cout;

#include <string>
using std::stoul;
using std::string;

#include <vector>
using std::vector;

#include "Statement.h"
#include "DataStructure.h"

int parseInsertStatement(const string& target, Row& insertRow) {
  string buffer{};
  vector<string> words;

  for (int i = 0; i < target.length(); i++) {
    // check if space char
    if (target[i] == char(32)) {
      string tmp(buffer);
      words.push_back(tmp);
      buffer.clear();

      continue;
    }

    buffer += target[i];
  }

  // append very last group
  words.push_back(buffer);

  insertRow.id = stoul(words[1], nullptr, 0);
  words[2].copy(insertRow.username, COLUMN_USERNAME_SIZE);
  words[3].copy(insertRow.email, COLUMN_EMAIL_SIZE);

  return 3;
}

#endif