all: main
CCX = g++

INCLUDE += -I/usr/local/include/opencv 
INCLUDE += -I/usr/local/include

LDFLAGS += -L/usr/local/lib
LDFLAGS += -lopencv_world

CFLAGS = -g -Wall -ansi

main: main.o
	$(CXX) -o main main.o $(LDFLAGS)
main.o: main.cpp
	$(CXX) -c main.cpp $(INCLUDE) $(CFLGS)

clean:
	rm -rf *.o main 
