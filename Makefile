CC = g++
LDFLAGS =
CFLAGS = -I include -g -c -std=c++11 -w
SRC = $(wildcard *.cpp src/*.cpp)
HEAD = $(wildcard include/Compiler/*.h)
OBJ = $(SRC:.cpp=.o)
EXEC = main

all: $(OBJ) $(EXEC) $(HEAD)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o src/*.o out* $(EXEC)