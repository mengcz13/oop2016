comptime.out:polynomial.o posynomial.o comptime.o func.h
	g++ polynomial.o posynomial.o comptime.o -o comptime.out
polynomial.o:polynomial.cpp func.h
	g++ -c polynomial.cpp -o polynomial.o
posynomial.o:posynomial.cpp func.h
	g++ -c posynomial.cpp -o posynomial.o
comptime.o:comptime.cpp func.h
	g++ -c comptime.cpp -o comptime.o
