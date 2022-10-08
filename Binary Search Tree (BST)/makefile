all: bst

bst: bst.o node.o
	g++ -std=c++11 bst.o node.o -o bst

bst.o: bst.cpp node.h
	g++ -std=c++11 -c bst.cpp

node.o: node.cpp node.h
	g++ -std=c++11 -c node.cpp

clean:
	rm -rf *.o
	rm bst

run: bst
	./bst