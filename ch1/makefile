LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXX=g++

OBJ=Main.o

%.o: %.cpp
	$(CXX) -c $^

Main: $(OBJ)
	$(CXX) $^ -o $@ $(LIBS)

clean:
	rm -f *.o Main
