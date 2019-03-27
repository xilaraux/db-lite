#include <gtest/gtest.h>

#include "../src/Utils.h"

TEST(testTimesTwo, integerTests){
	Row* insertRow = new Row;
	string target = "insert 1 a q";

	parseInsertStatement(target, *insertRow);

	EXPECT_EQ(1, insertRow->id);
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

