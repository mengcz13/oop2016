main:mst.o graph.o main.o
	g++ -O2 $^ -o $@
main.o:main.cpp graph.h mst.h
	g++ -c -O2 main.cpp -o $@
mst.o:mst.cpp mst.h
	g++ -c -O2 mst.cpp -o $@
graph.o:graph.cpp graph.h
	g++ -c -O2 graph.cpp -o $@
clean:
	rm main.o graph.o mst.o
