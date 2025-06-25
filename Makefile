all: main

main: main.o Life.o
	g++ main.o Life.o -o main

main.o: main.cpp Life.h
	g++ -c main.cpp

Life.o: Life.cpp
	g++ -c Life.cpp

clean:
	rm -f *.o main