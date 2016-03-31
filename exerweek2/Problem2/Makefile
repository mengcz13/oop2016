main.out:header.o main.o header.h
	g++ header.o main.o -o main.out
header.o:header.cpp header.h
	g++ -c header.cpp -o header.o
main.o:main.cpp header.h
	g++ -c main.cpp -o main.o
