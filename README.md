# Library Database

This is a file based database system. It keeps track of available books, libraries, and holdings of books that libraries have. 

## Project Description

This project was built to become more familiar with the needs for a true database system.

## Installation

In the terminal:
Use make to create an executable called run, then use ./run to run the file. 

## Usage

You can call "l", which is followed by "b" (lists books) or "l" (lists libraries). You can call "a", followed by "b" and book info (ISBN, Year, Author, Title) which then adds the Book to the file; or followed by "l" and library info (Name, City, ZipCode) which then adds a Library to the corresponding file; or followed by "h" and a Library name and Book ISBN which adds a holding to the corresponding file. You can also input "f" followed by an ISBN number to find current holdings which includes the library they are at, the book's info, and copy number.

## Development Log

Initialized project. Added Book, Library, and Holding classes. Built constructors and <<, >> overloads for each.

Added BookList, LibraryList, and HoldingList classes. Built out the full capabilites needed of Book, BookList, Library, and LibraryList classes. Stuggled with HoldingList.

Still struggling with HoldingList. 

Made big changes to Holding and HoldingList got it correctly taking in a Library name and Book. 

Fully fixed Holding and HoldingList bugs. Just need to clean up code and test extensively.

Cleaned up code. Tested and found some minor bugs.

Fixed the minor bugs.

Adjusted code for BookList, LibraryList, and HoldingList to use a dynamically allocated array instead of a set size. PROJECT COMPLETED. 