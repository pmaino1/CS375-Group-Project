P1= main

CFLAGS= -O3 -g -Wall -std=c++14

all: $(P1)

$(P1): $(P1).o
	g++ $(CFLAGS) $(P1).o -o $(P1)

$(P1).o: $(P1).cpp
	g++ $(CFLAGS) -c $(P1).cpp -o $(P1).o


clean:
	rm -rf *.o $(P1)

run: all
	./$(P1)

memcheck: all
	valgrind ./$(P1)
