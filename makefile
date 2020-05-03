P1= dfsImplementation
P2= tester

CFLAGS= -O3 -g -Wall -std=c++14

all: $(P1).o $(P2).o
	g++ $(CFLAGS) $(P1).o $(P2).o -o $(P2)

$(P1).o: $(P1).cpp
	g++ $(CFLAGS) -c $(P1).cpp -o $(P1).o

$(P2).o: $(P2).cpp
	g++ $(CFLAGS) -c $(P2).cpp -o $(P2).o

clean:
	rm -rf *.o $(P1) $(P2)

run: all
	./$(P2)

memcheck: all
	valgrind ./$(P2)
