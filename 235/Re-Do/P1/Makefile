CXXFLAGS=-std=c++11

main: main.o Customer.o GeniusBar.o
	g++ -o main main.o Customer.o GeniusBar.o

main.o: main.cpp Customer.hpp GeniusBar.hpp
	g++ $(CXXFLAGS) -c main.cpp

Customer.o: Customer.hpp
	g++ $(CXXFLAGS) -c Customer.cpp

GeniusBar.o: GeniusBar.hpp Customer.hpp
	g++ $(CXXFLAGS) -c GeniusBar.cpp

clean:
	rm -f *.o
