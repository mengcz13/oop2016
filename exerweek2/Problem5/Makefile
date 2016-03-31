main.out:sampleclass.o main.o sampleclass.h
	g++ sampleclass.o main.o -o main.out
sampleclass.o:sampleclass.cpp sampleclass.h
	g++ -c sampleclass.cpp -o sampleclass.o
main.o:main.cpp sampleclass.h
	g++ -c main.cpp -o main.o
