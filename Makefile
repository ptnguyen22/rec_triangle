all: TFractal
TFractal: Triangle.o TFractal.o
	g++ -O3 Triangle.o TFractal.o -o TFractal -lsfml-graphics -lsfml-window -lsfml-system
Triangle.o: Triangle.cpp Triangle.h
	g++ -c Triangle.cpp
TFractal.o: TFractal.cpp
	g++ -c TFractal.cpp
clean:
	rm *.o TFractal
