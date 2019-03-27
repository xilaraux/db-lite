CPP = g++
RM = rm -f
CPP_FLAGS = -o
TEST_FLAGS = -std=c++11 -isystem ./googletest/googletest/include/ -pthread

SRC = $(wildcard src/*.cpp)
SRC_H = $(wildcard src/*.h)
TESTS = $(wildcard tests/*.cpp)
OBJECTS := $(SRC)
TEST_O := $(TESTS)
ARTIFACT_NAME = bin/db.o
ARTIFACT_TEST = bin/db_test.o

build: $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $(ARTIFACT_NAME) $(OBJECTS)

test: $(TEST_O)
	$(CPP) $(TEST_FLAGS) $(OBJECTS) $(TEST_O) ./googletest/googletest/libgtest.a -o $(ARTIFACT_TEST)

clean:
	$(RM) $(ARTIFACT_NAME) $(ARTIFACT_TEST)

