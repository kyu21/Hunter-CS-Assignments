CXXFLAGS=-std=c++11

main: main.o Song.o PlayList.o
	g++ -o main main.o Song.o PlayList.o

main.o: main.cpp Song.h PlayList.h Set.h SetInterface.h
	g++ $(CXXFLAGS) -c main.cpp

PlayList.o: PlayList.cpp Set.h Song.h PlayList.h
	g++ $(CXXFLAGS) -c PlayList.cpp

Song.o: Song.cpp Song.h
	g++ $(CXXFLAGS) -c Song.cpp

Set.o: Set.cpp Set.h SetInterface.h
	g++ $(CXXFLAGS) -c Set.cpp

clean:
	rm -f *.o
