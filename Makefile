run: Book.o Library.o Holding.o main.o
	g++ -o run Book.o Library.o Holding.o main.o

Book.o: Book.hpp Book.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 Book.cpp

Library.o: Library.hpp Library.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 Library.cpp

Holding.o: Holding.hpp Holding.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 Holding.cpp

main.o: Book.hpp main.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 main.cpp
