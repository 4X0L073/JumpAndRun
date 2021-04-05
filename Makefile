TARGET = dino
LIBS = -lncurses
CC = g++
CFLAGS = -g -Wall -std=c++11 

.PHONY: default all clean run $(TARGET)

default: $(TARGET)
all: default 

SOURCES = BoxObstacle.cpp Dino.cpp Floor.cpp Game.cpp Rectangle.cpp Terminal.cpp main.cpp 
HEADERS = BoxObstacle.h Dino Floor.h Game.h Rectangle.h Terminal.h

$(TARGET):
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $@

run:
	./$(TARGET)
	
clean:
	-rm -f $(TARGET)