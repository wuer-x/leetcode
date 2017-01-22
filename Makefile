target : main.o
	g++ -o target main.o

main.o : ../412_fizz_buzz/main.cpp
	g++ -o main.o ../412_fizz_buzz/main.cpp
