run: Book.o BookList.o Library.o LibraryList.o Holding.o HoldingList.o main.o
	g++ -o run Book.o BookList.o Library.o LibraryList.o Holding.o HoldingList.o main.o

Book.o: Book.hpp Book.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 Book.cpp

BookList.o: BookList.hpp BookList.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 BookList.cpp

Library.o: Library.hpp Library.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 Library.cpp

LibraryList.o: LibraryList.hpp LibraryList.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 LibraryList.cpp

Holding.o: Holding.hpp Holding.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 Holding.cpp

HoldingList.o: HoldingList.hpp HoldingList.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 HoldingList.cpp

main.o: Book.hpp main.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 main.cpp
