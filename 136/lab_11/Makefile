CXXFLAGS=-std=gnu++14

main: main.o funcs.o poem.o
		g++ -o main main.o funcs.o

main.o: main.cpp def.h
		g++ $(CXXFLAGS) -c main.cpp

funcs.o: funcs.cpp def.h
		g++ $(CXXFLAGS) -c funcs.cpp

tests: tests.o funcs.o
		g++ -o tests tests.o funcs.o

tests.o: tests.cpp def.h

poem: poem.o
		g++ -o poem poem.o

poem.o:
		g++ $(CXXFLAGS) -c poem.cpp

clean:
		rm -f main.o funcs.o *.o *.out