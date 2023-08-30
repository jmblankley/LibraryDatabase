# Library Database
### Author: Joshua M. Blankley
### Date: August 30 2023

## Project Description

This project was built to become more familiar with the needs for a true database system. It is a file based database system that keeps track of available books, libraries, and holdings of books that libraries have. Note: The files have been left empty so that you can use them with your own data.

## Technologies Used

I built this project using C++ in an Ubuntu VM. 

## Installation

In the terminal:
Use make to create an executable called run, then use ./run to run the file.

## Usage

The following commands are available for interacting with the application:

### List Command

To list items, use the `l` command followed by:

- `b` to list books
- `l` to list libraries

Example:
```console
>>>l b
12345 2000 Smith Database Fun
54321 1996 Johns C++ Is Awesome
```


### Add Command

To add items, use the `a` command followed by:

- `b` and book info (ISBN, Year, Author, Title) to add a Book
- `l` and library info (Name, City, ZipCode) to add a Library
- `h`, a Library name, and Book ISBN to add a holding

Examples:
```console
>>>a b 12345 2000 Smith Database Fun
```
```console
>>>a l PublicLibrary Ofallon 98762
```
```console
>>>a h 12345 PublicLibrary
```


### Find Command

To find current holdings, use the `f` command followed by an ISBN number.

Example:
```console
>>>f 12345
PublicLibrary: 12345 2000 Smith Database Fun Copy Number: 1
```



## Development Log

Initialized project. Added Book, Library, and Holding classes. Built constructors and <<, >> overloads for each.

Added BookList, LibraryList, and HoldingList classes. Built out the full capabilites needed of Book, BookList, Library, and LibraryList classes. Stuggled with HoldingList.

Still struggling with HoldingList. 

Made big changes to Holding and HoldingList got it correctly taking in a Library name and Book. 

Fully fixed Holding and HoldingList bugs. Just need to clean up code and test extensively.

Cleaned up code. Tested and found some minor bugs.

Fixed the minor bugs.

Adjusted code for BookList, LibraryList, and HoldingList to use a dynamically allocated array instead of a set size. PROJECT COMPLETED. 
