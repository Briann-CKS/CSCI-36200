all: hash

hash: hash.o main.o
	g++ -std=c++11 hash.o main.o -o hash

hash.o: hash.cpp hash.h
	g++ -std=c++11 -c hash.cpp

main.o: main.cpp hash.h
	g++ -std=c++11 -c main.cpp

clean:
	rm -rf *.o
	rm hash

run: hash
	./hash