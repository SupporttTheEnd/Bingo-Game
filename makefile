CXX = g++
CXXFLAGS = -Wall

p: mytest.cpp bingo.o 
	$(CXX) $(CXXFLAGS) mytest.cpp bingo.o -o proj0

d: driver.cpp bingo.o 
	$(CXX) $(CXXFLAGS) driver.cpp bingo.o -o proj0

bingo.o: bingo.h bingo.cpp
	$(CXX) $(CXXFLAGS) -c bingo.cpp

clean:
	rm *.o*
	rm *~ 

v:
	valgrind --leak-check=full --track-origins=yes ./proj0

r:
	./proj0
