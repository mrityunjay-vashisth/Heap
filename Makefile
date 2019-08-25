CC=gcc
CXX=g++ -std=c++11
CFLAGS=-I.

MinHeap: MinHeap.o 
	$(CXX) -o MinHeap MinHeap.o 