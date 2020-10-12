LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXX=g++
CXXFLAGS=-std=c++11

OBJ=main.o window.o game.o

%.o: %.cpp
	$(CXX) -c $^

main: $(OBJ)
	$(CXX) $^ -o $@ $(LIBS)

clean:
	rm -f *.o main
