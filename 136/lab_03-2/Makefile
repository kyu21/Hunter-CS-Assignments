CXXFLAGS=-std=c++14

main: main.o funcs.o
	g++ -o main main.o funcs.o

main.o: main.cpp funcs.h doctest.h
	g++ $(CXXFLAGS) -c main.cpp

funcs.o: funcs.cpp funcs.h
	g++ $(CXXFLAGS) -c funcs.cpp

tests: tests.o funcs.o
	g++ -o test tests.o funcs.o

tests.o: tests.cpp funcs.h

clean:
	rm -f main.o funcs.o tests.o
