# Makefile
# Include -g flag to get debugging information
# valgrind: memory check and produces a report
all: stlqueue bfs

stlqueue: queue.cpp
	g++ -g --std=c++11 queue.cpp -o stlqueue

bfs: bfs.cpp bst.cpp
	g++ -g --std=c++11 bst.cpp bfs.cpp -o bfs

clean:
	rm stlqueue bfs
