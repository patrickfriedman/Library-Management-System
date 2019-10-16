#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

void get_date(int &m, int &d, int &y);

struct Date
{
	int month, day, time;
};

struct Student
{
	string euid;
	int number_of_books_borrowed;
	long int *list_of_isbn;
} student;

struct Book
{
	string author_name, book_name, euid_b;
	long int isbn;
	Date borrowed;
} book;
