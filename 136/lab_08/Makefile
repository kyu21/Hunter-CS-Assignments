CXXFLAGS=-std=gnu++14

main: unindent indent

unindent: unindent.o
	g++ -o unindent unindent.o

unindent.o: unindent.cpp
	g++ $(CXXFLAGS) -c unindent.cpp

indent: indent.o
	g++ -o indent indent.o

indent.o: indent.cpp
	g++ $(CXXFLAGS) -c indent.cpp

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
	$(RM) unindent.o indent.o