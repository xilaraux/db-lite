CPP = g++
RM = rm -f
CPP_FLAGS = -o -I./googletest/include
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
ARTIFACT_NAME = db.o

build: $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $(ARTIFACT_NAME) $(OBJECTS)

clean:
	$(RM) $(ARTIFACT_NAME)

