main: main.o fun.o
	g++ -o main main.o fun.o

fun.o: fun.cpp header.h
	g++ -c fun.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o
	rm -f main 
