CXXFLAGS=-std=c++11

main: main.o SortingTests.o
	g++ -o main main.o SortingTests.o

main.o: main.cpp SortingTests.hpp
	g++ $(CXXFLAGS) -c main.cpp

SortingTests.o: SortingTests.cpp SortingTests.hpp
	g++ $(CXXFLAGS) -c SortingTests.cpp

clean:
	rm -f *.o

wclean:
	del /Q *.o