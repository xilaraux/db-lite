CPP = g++
RM = rm -f
CPP_FLAGS = -o
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
ARTIFACT_NAME = db.o

build: $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $(ARTIFACT_NAME) $(OBJECTS)

test: basic_test.cpp
	g++ -std=c++11 -isystem ./googletest/googletest/include/ -pthread basic_test.cpp ./googletest/googletest/libgtest.a -o basic_test.o

clean:
	$(RM) $(ARTIFACT_NAME)

