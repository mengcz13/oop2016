main.out:videotape.o main.o videotape.h
	g++ videotape.o main.o -o main.out
videotape.o:videotape.cpp videotape.h
	g++ -c videotape.cpp -o videotape.o
main.o:main.cpp videotape.h
	g++ -c main.cpp -o main.o
