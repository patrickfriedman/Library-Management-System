#include "my_header.h"

int number_of_students();	//number of students in the file
int number_of_books();		//number of books in the file

void header();		//prints the file

void enter_book();	//add book function
void check_out();	//check out function
void return_book();	//return book function
void search_book();	//search book function

void search_by_author();	//search by author function
void search_by_title();	//search by title function
void search_by_student();	//search by student function

int main()
{
	int choice;		//number of choices
	bool success;	//if it was a valid choice

	system("cls");	//clear
	header();	//print header

	do
	{
		cout << endl << "1. Add" << endl;	//enter book function

		cout << "2. Check Out" << endl;		//check out function

		cout << "3. Return" << endl;	//return functiom

		cout << "4. Search" << endl;	//search function

		cout << "Enter your choice, 0 to Quit: ";	//0 to quit

		cin >> choice;		//get choice
		cin.ignore();		//ignore cin value

		do
		{
			switch(choice)
			{
				case 0:			//quit
					return 0;
					break;
				case 1:
					enter_book();	//enter book
					success = true;
					break;
				case 2:
					check_out();		//check out
					success = true;
					break;
				case 3:
					return_book();	//return
					success = true;
					break;
				case 4:
					search_book();		//search
					success = true;
					break;
				default:
					cout << "Wrong Choice. Enter again.";		//wrong choice, restart
					success = false;
					cout << endl;
					break;
			}

			break;

		} while(!success);		//end loop if valid choice

	} while(choice != 0);		//end loop when user enters 0

	return 0;
}

/*
==================================================
Function: number_of_students()
Parameters: NA
Return: Void
Description: Find the number of students in the file.
==================================================
*/

int number_of_students()
{
	string line;
	int count = 0;	//counter for number of students

	ifstream fin;
	fin.open("students.txt");	//open file

	while (getline(fin, line))
	{
		++count;	//add one student
	}

	return count;		//count for students
}

/*
==================================================
Function: number_of_books()
Parameters: NA
Return: Void
Description: Find the number of books.
==================================================
*/

int number_of_books()
{
	string line;
	int count = 0;	//counter for number of books

	ifstream fin;
	fin.open("books.txt");		//open file

	while (getline(fin, line))
	{
		++count;	//add one book
	}

	return count;		//count for books
}

/*
==================================================
Function: header()
Parameters: NA
Return: Void
Description: Print the header.
==================================================
*/

void header()
{
	cout << "+--------------------------------------------------------+" << endl;
	cout << "|            Computer Science and Engineering            |" << endl;
	cout << "|             CSCE 1030 - Computer Science I             |" << endl;
	cout << "|   Patrick Friedman     psf0023    psf0023@my.unt.edu   |" << endl;
	cout << "+--------------------------------------------------------+" << endl;

	return;
}

/*
==================================================
Function: get_date()
Parameters: NA
Return: Void
Description: Get the date.
==================================================
*/

void get_date(int& month, int&day, int& year)
{
	time_t my_time = time(0);
	tm* now = localtime(&my_time);
	year = now -> tm_year + 1900;
	month = now -> tm_mon + 1;
	day = now -> tm_mday;

	return;
}

/*
==================================================
Function: enter_book()
Parameters: NA
Return: Void
Description: Add a book to database.
==================================================
*/

void enter_book()
{
	ofstream enterBook;
	enterBook.open("books.txt", ios::app);		//open file and append to file

	cout << "Enter book was selected." << endl;
	cout << endl;

	cout << "Enter the full name of the author: ";		//ask for author name
	getline(cin, book.author_name);		//get author from text file
	cout << endl;

	cout << "Enter the title of the book: ";		//ask for book title
	getline(cin, book.book_name);		//get book title from text file
	cout << endl;

	cout << "Enter the ISBN of the book: ";
	cin >> book.isbn;		//get book isbn number from text file

	string isbn_s = to_string(book.isbn);		//change long int to string

    for (int x = 0; x < book.author_name.size(); x++)		//find the string size
    {
 	   enterBook.put(book.author_name.at(x));		//place all characters
 	}
    enterBook << "\t";		//tend to the white space

    for (int y = 0; y < book.book_name.size(); y++)		//find the string size
    {
 	   enterBook.put(book.book_name.at(y));		//place all characters
 	}
    enterBook << "\t";   		//tend to the white space

    for (int z = 0; z < isbn_s.size(); z++)		//find the string size
    {
 	   enterBook.put(isbn_s.at(z));		//place all characters
 	}

    enterBook << '\t' << "NA" << '\t' << "0" << '\t' << "0" << '\t' << "0";		//put NA and 0 for check out
    enterBook << endl;	//ready for next book

	cout << "Book successfully added." << endl;

	enterBook.close();		//close file

	return;
}

/*
==================================================
Function: check_out()
Parameters: NA
Return: Void
Description: Check out students book.
==================================================
*/

void check_out()
{
	int count = number_of_students();		//get the count of number of students
	string search_euid;		//search euid
	ifstream checkOut;		//read file stream
	checkOut.open("students.txt");		//open student file

	cout << "Check out book was selected." << endl;
	cout << endl;

	cout << "Enter your EUID: ";		//enter user euid
	cin >> student.euid;	//read in

	for (int i = 0; i < count; i++) {		//loop through number of students
		checkOut >> search_euid >> student.number_of_books_borrowed;		//get files from txt file

		if (student.euid.compare(search_euid) == 0)		//check if user entered id and file id is the same
		{
			cout << "Valid EUID." << endl;
			cout << endl;

			if (student.number_of_books_borrowed < 5)		//check if the number of books checked out is less than 5
			{
				int number_of_books_C = number_of_books();		//get the number of books
				string search_isbn;
				ifstream isbnSearch;		//read stream
				ofstream num_o_b_b;		//write stream
				isbnSearch.open("books.txt");			//open file
				num_o_b_b.open("students.txt", ios::app);		//open file and append

				cout << "Enter the ISBN of the book: ";		//enter book isbn
				cin >> book.isbn;

				string isbn_s = to_string(book.isbn);		//change int to string

				for (int i = 0; i < number_of_books_C; i++)			//loop through all books
				{
					getline(isbnSearch, book.author_name, '\t'); 		//may error
					getline(isbnSearch, book.book_name, '\t');		//get all files in book text file
					getline(isbnSearch, search_isbn, '\t');
					getline(isbnSearch, book.euid_b, '\t');
					isbnSearch >> book.borrowed.month >> book.borrowed.day >> book.borrowed.time;

					if (isbn_s.compare(search_isbn) == 0)		//compare user entered isbn and text file isbn
					{
						cout << "Valid ISBN." << endl;
						cout << endl;

						if (book.euid_b.compare("NA") == 0)		//check if book is checked out
						{
							cout << "No one has checked book out." << endl;
							get_date(book.borrowed.month, book.borrowed.day, book.borrowed.time);		//get date
							cout << endl << book.borrowed.month << " " << book.borrowed.day << " " << book.borrowed.time << endl;
						}
						else
						{
							cout << "Book is currently checked out." <<endl;		//end loop if book is checked out
							break;
						}

						++student.number_of_books_borrowed;		//increment the students number of books borrowed
						cout << endl << "Checked out successfully." << endl;
						cout << "The number of books you have borrowed is now: " << student.number_of_books_borrowed << endl;

						string num_o_b_b_s = to_string(student.number_of_books_borrowed);		//change int to a string

						//Traverse through students.txt
						//while(int j=0;j<count;j++){
						//getline(num_o_b_b,student.euid);
						//if(student.euid.compare(search_euid))

						//num_o_b_b.put(num_o_b_b_s.at(0));
						//update students file to add one borrowed book

						num_o_b_b.close();			//close file
						break;
					}
				}

				if (isbn_s.compare(search_isbn) != 0)			//compare user isbn and file isbn
				{
					cout << endl << "Error, ISBN not in the database." << endl;		//if not quit
					break;
				}

				isbnSearch.close();			//close file
				break;
			}
			else
			{
				cout << "Cannot check out over 5 books." << endl; 		//end if number of books checked out > 5
			}
		}
	}

	if (student.euid.compare(search_euid) != 0) 		//compare user euid to file euid
	{
		cout << "EUID not in database, no books may be borrowed." << endl;
	}

	checkOut.close();			//close file

	return;
}

/*
==================================================
Function: return_book()
Parameters: NA
Return: Void
Description: Return book.
==================================================
*/

void return_book()
{
	int number_of_books_C = number_of_books();		//find number of books
	string search_isbn;
	ifstream returnBook;		//read stream
	returnBook.open("books.txt");		//open file

	cout << "Return book was selected." << endl;
	cout << endl;

	cout << "Enter the book ISBN: ";		//enter book isbn
	cin >> book.isbn;

	string isbn_s = to_string(book.isbn);		//change int to string

	for (int i = 0; i < number_of_books_C; i++)		//loop through all books
	{
		getline(returnBook, book.author_name, '\t');
		getline(returnBook, book.book_name, '\t');		//go through each value
		getline(returnBook, search_isbn, '\t');
		getline(returnBook, book.euid_b, '\t');
		returnBook >> book.borrowed.month >> book.borrowed.day >> book.borrowed.time;		//get time and date

		if (isbn_s.compare(search_isbn) == 0)		//compare user isbn with file isbn
		{
			cout << "Valid ISBN." << endl;
			cout << endl;

			ofstream bookUpdate;		//write stream
			bookUpdate.open("books.txt", ios::app);		//open file and append

			if (book.euid_b.compare("NA") == 0)		//check if no one has checked book out
			{

			//    enterBook << '\t' << "NA" << '\t' << "0" << '\t' << "0" << '\t' << "0";
			//    enterBook << endl;

				student.number_of_books_borrowed--;		//decrement books borrowed by one
				cout << "Returned book successfully." << endl;
				cout << "The number of books you have borrowed is now: " << student.number_of_books_borrowed << endl;

				string num_o_b_b_s = to_string(student.number_of_books_borrowed);		//change int to string

				//bookUpdate.put(num_o_b_b_s.at(1));
				//update students file to subtract one borrowed book
			}
		else
		{
			cout << "Book is already checked out." <<endl;		//end loop if book was checked out
		}

			bookUpdate.close();		//close file
			break;
		}
	}

	if (isbn_s.compare(search_isbn) != 0)		//check if isbn is in database
	{
		cout << endl << "Error, ISBN not in the database." << endl;		//end loop if not the same
	}

	returnBook.close();		//close file

	return;
}

/*
==================================================
Function: search_book()
Parameters: NA
Return: Void
Description: Search book database.
==================================================
*/

void search_book()
{
	int choice;		//choices for switch
	bool success = false;		//check if a valid choice

	cout << "Search book was selected." << endl;
	cout << endl;

	do {
		cout << "What do you want to search with?" << endl;		//enter choices
		cout << "1. Author" << endl;
		cout << "2. Title" << endl;
		cout << "3. Student" << endl;
		cout << "Enter your choice: ";

		cin >> choice;		//get choice from user
		cin.ignore();			//ignore choice

		do
		{
			switch(choice)		//choices
			{
				case 1:
					cout << "Search by author was selected." << endl;
					cout << endl;
					search_by_author();		//call search author function
					success = true;
					break;
				case 2:
					cout << "Search by title was selected." << endl;
					cout << endl;
					search_by_title();		//call search by title function
					success = true;
					break;
				case 3:
					cout << "Search by student was selected." << endl;
					cout << endl;
					search_by_student();		//call search by student function
					success = true;
					break;
				default:
					cout  << "Wrong choice. Enter again." << endl;
					cout << endl;
					success = false;		//check if valid choice
					break;
			}

			break;

		} while(!success);		//check if valid choice

	} while(choice != 1 && choice != 2 && choice != 3);		//if valid

	return;
}

/*
==================================================
Function: search_by_author()
Parameters: NA
Return: Void
Description: Search book database for author.
==================================================
*/

void search_by_author()
{
	int number_of_books_C = number_of_books();		//get number of book
	string search_author_s;
	string author[number_of_books_C];		//author array

	ifstream search_author;		//read stream
	search_author.open("books.txt");		//open text file

	cout << "Enter the author: ";
	cin >> search_author_s;		//enter author
	cout << endl;

	for (int i = 0; i < number_of_books_C; i++)		//loop through the books
	{
		getline(search_author, author[i]);		//get values from text file

		if (author[i].find(search_author_s) == 0)		//check if user and file are the same
		{
			cout << author[i] << endl;		//print all books with those characters
 		}
	}

	search_author.close();		//close file

	return;
}

/*
==================================================
Function: search_by_title()
Parameters: NA
Return: Void
Description: Search book database by title.
==================================================
*/

void search_by_title()
{
	int number_of_books_C = number_of_books();		//number of books value
	string search_title_s;
	string title[number_of_books_C];		//title array

	ifstream search_title;		//read stream
	search_title.open("books.txt");		//open file

	cout << "Enter the title: ";
	cin >> search_title_s;		//title input
	cout << endl;

	for (int i = 0; i < number_of_books_C; i++)			//loop through books
	{
		getline(search_title, book.author_name, '\t');		//go through line by line
		getline(search_title, title[i]);

		if (title[i].find(search_title_s) == 0)		//compare user input to text file
		{
			cout << title[i] << endl;			//print titles
 		}
	}

	search_title.close();		//close file

	return;
}

/*
==================================================
Function: search_by_student()
Parameters: NA
Return: Void
Description: Search book database by student.
==================================================
*/

void search_by_student()
{
	int number_of_books_C = number_of_books();		//get num of books
	int count = number_of_students(); 	//get num of students
	string search_student_s;
	string euid[number_of_books_C];		//euid array
	string isbn_s = to_string(book.isbn);		//change int to string

	ifstream search_student;			//read stream
	search_student.open("books.txt");		//open file

	cout << "Enter the student: ";
	cin >> search_student_s;		//get student euid
	cout << endl;

	for (int i = 0; i < number_of_books_C; i++)		//loop through all books
	{
		getline(search_student, book.author_name, '\t');		//get all files from text line by line
		getline(search_student, book.book_name, '\t');
		getline(search_student, isbn_s, '\t');
		getline(search_student, euid[i]);

		if (euid[i].find(search_student_s) == 0)		//compare user euid and file input
		{
			cout << euid[i] << endl;		//print euids
 		}

 		for (int i = 0; i < count; i++)		//loop through number of students
 		{
 			ifstream num_o_b_b;
 			num_o_b_b.open("students.txt");

			num_o_b_b >> book.euid_b >> student.number_of_books_borrowed;		//get files from txt file

	 		if (student.number_of_books_borrowed == 0)		//checks if 0
	 		{
	 			cout << "Does not have any books borrowed." << endl;		//print if no books are borrowed
	 			break;
	 		}
	 	}
	}

	search_student.close();		//close file

	return;
}
