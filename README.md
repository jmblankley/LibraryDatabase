# Library Database
**Author:** Joshua M. Blankley  
**Date:** August 30, 2023

## Project Description

This project aims to enhance understanding of the requirements for a comprehensive database system (file based). It is a file-based database system designed to manage information about available books, libraries, and the holdings of books within those libraries. Note: The provided files are intentionally empty to allow usage with your own data.

This project is fully built in C++ without the use of any relational database for practice purposes. Please do not use this as a functional application as there are many issues with file based database systems.

## Technologies Used

I built this project using C++ in an Ubuntu VM. 

## Installation

In the terminal:
1. Use `make` to compile and generate an executable named `run`.
2. Execute the program using `./run`.

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

- Initialized project. Added Book, Library, and Holding classes. Implemented constructors and `<<`, `>>` overloads for each.
- Added BookList, LibraryList, and HoldingList classes. Fully developed necessary capabilities for Book, BookList, Library, and LibraryList classes. Encountered challenges with HoldingList.
- Continued struggling with HoldingList.
- Made significant changes to Holding and HoldingList, resolved issues regarding Library name and Book.
- Successfully resolved all bugs in Holding and HoldingList. Final tasks involve code cleanup and extensive testing.
- Cleaned up the code. Conducted testing and identified minor issues.
- Rectified the minor issues.
- Revised code for BookList, LibraryList, and HoldingList to utilize dynamically allocated arrays instead of fixed sizes. **PROJECT COMPLETED.**

