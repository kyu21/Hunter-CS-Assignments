CXXFLAGS=-std=gnu++14

taska: social.o profile.o
		g++ -o taska social.o profile.o

social.o: social.cpp Profile.h
		g++ $(CXXFLAGS) -c social.cpp

profile.o: Profile.cpp Profile.h
		g++ $(CXXFLAGS) -c Profile.cpp

taskb: social2.o network.o profile.o
		g++ -o taskb social2.o network.o profile.o

social2.o: social2.cpp Network.h 
		g++ $(CXXFLAGS) -c social2.cpp

network.o: Network.cpp Network.h
		g++ $(CXXFLAGS) -c Network.cpp

taskc: social3.o network2.o profile.o
		g++ -o taskc social3.o network2.o profile.o

social3.o: social3.cpp Network2.h 
		g++ $(CXXFLAGS) -c social3.cpp

network2.o: Network2.cpp Network2.h
		g++ $(CXXFLAGS) -c Network2.cpp
clean:
		rm -f main.o funcs.o *.o