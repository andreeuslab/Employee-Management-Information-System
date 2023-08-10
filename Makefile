all: main
main: main.o
	g++ -Wall -g -o main main.o

main.o: main.cpp
	g++ -Wall -g -c main.cpp

clean:
	rm main.o main
