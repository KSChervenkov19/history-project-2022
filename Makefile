output: main.o
	g++ -std=c++20 main.o -o output
	./output.exe

main.o: main.cpp
	g++ -c main.cpp