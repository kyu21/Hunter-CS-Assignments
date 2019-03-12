CXXFLAGS=-std=gnu++14

main: main.o funcs.o
	g++ -o main main.o funcs.o

main.o: main.cpp funcs.h doctest.h
	g++ $(CXXFLAGS) -c main.cpp

funcs.o: funcs.cpp funcs.h
	g++ $(CXXFLAGS) -c funcs.cpp

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

tests.o: tests.cpp funcs.h

ifdef SYSTEMROOT
   RM = del /Q
   FixPath = $(subst /,\,$1)
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
      FixPath = $1
   endif
endif
clean:
	$(RM) main.o funcs.o tests.o