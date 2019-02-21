CXXFLAGS=-std=gnu++14

main: main.o Customer.o GeniusBar.o
	g++ -o main main.o Customer.o GeniusBar.o

main.o: main.cpp Customer.hpp GeniusBar.hpp
	g++ $(CXXFLAGS) -c main.cpp

Customer.o: Customer.hpp

GeniusBar.o: GeniusBar.hpp Customer.hpp

clean:
	rm -f main.o Customer.o GeniusBar.o
