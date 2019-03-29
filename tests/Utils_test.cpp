#include <gtest/gtest.h>

#include <string>
using std::string;

#include "../src/Utils.h"

TEST(testUtils, parseInsertStatement){
	Row* row = new Row;
	
	string target = "insert 1 username email@email.com";

	parseInsertStatement(target, *row);

	EXPECT_EQ(1, row->id);
	EXPECT_STREQ("username", row->username);
	EXPECT_STREQ("email@email.com", row->email);

	// Second test
	row = new Row;
	target = "insert 2   vasya       ema@company.com";

	parseInsertStatement(target, *row);

	EXPECT_EQ(2, row->id);
	EXPECT_STREQ("vasya", row->username);
	EXPECT_STREQ("ema@company.com", row->email);
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

