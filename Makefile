CC = g++
CFLAGS = -Wall -g
 
main: main.o matrix.o
	$(CC) $(CFLAGS) -o main main.o matrix.o
 
main.o: main.cpp matrix.hpp
	$(CC) $(CFLAGS) -c main.cpp matrix.cpp
 
matrix.o: matrix.hpp 

clean:
	rm -rf *.o
	rm main
