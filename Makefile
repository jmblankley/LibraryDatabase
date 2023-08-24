run: Book.o BookList.o Library.o main.o
	g++ -o run Book.o BookList.o Library.o main.o

Book.o: Book.hpp Book.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 Book.cpp

BookList.o: BookList.hpp BookList.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 BookList.cpp

Library.o: Library.hpp Library.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 Library.cpp

main.o: Book.hpp main.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 main.cpp
