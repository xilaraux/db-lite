CPP = g++
RM = rm -f
CPP_FLAGS = -std=c++11 -o
TEST_FLAGS = -std=c++11 -isystem ./googletest/googletest/include/ -pthread

SRC = $(wildcard src/*.cpp)
SRC_H = $(wildcard src/*.h)
TESTS = $(wildcard tests/*.cpp)
TEST_SRC := $(filter-out src/main.cpp, $(SRC_H) $(SRC) $(TESTS))
ARTIFACT_NAME = bin/db.o
ARTIFACT_TEST = bin/db_test.o

build: $(SRC)
	$(CPP) $(CPP_FLAGS) $(ARTIFACT_NAME) $(SRC)

test: $(TEST_SRC)
	$(CPP) $(TEST_FLAGS) $(TEST_SRC) ./googletest/googletest/libgtest.a -o $(ARTIFACT_TEST)

clean:
	$(RM) $(ARTIFACT_NAME) $(ARTIFACT_TEST)

