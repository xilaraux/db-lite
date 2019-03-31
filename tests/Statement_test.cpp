#include <gtest/gtest.h>

#include <iostream>
using std::cout;

#include <sstream>
using std::stringstream;

#include "../src/Statement.h"

TEST(testStatement, Statement){	
	Statement* statement;
	PrepareResult result;
	InputBuffer input;
	stringstream* ss;

	// Testing insert statement
	statement = new Statement;
	ss = new stringstream;
	ss->str("insert 1 user email");
	input.read(*ss);
		
	result = statement->prepareStatement(input);
	
	EXPECT_EQ(PREPARE_SUCCESS, result);
	EXPECT_EQ(STATEMENT_INSERT, statement->getType());

	// Testing select statement
	statement = new Statement;
	ss = new stringstream;
	
	ss->str("select");
	input.read(*ss);

	result = statement->prepareStatement(input);
	
	EXPECT_EQ(PREPARE_SUCCESS, result);
	EXPECT_EQ(STATEMENT_SELECT, statement->getType());
}

