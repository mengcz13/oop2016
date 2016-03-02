main.out:sum.o mul.o main.o functions.h
	g++ sum.o mul.o main.o -o main.out
sum.o:sum.cpp functions.h
	g++ -c sum.cpp -o sum.o
mul.o:mul.cpp functions.h
	g++ -c mul.cpp -o mul.o
main.o:main.cpp functions.h
	g++ -c main.cpp -o main.o
