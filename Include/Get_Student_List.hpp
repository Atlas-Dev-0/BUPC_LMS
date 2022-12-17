#pragma once
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include "Console_Coloring_Header.h"
#include "Navigation_guis.hpp"

using namespace std;

// Defines a class to store information about a borrowed book
class BorrowedBook_Information
{
    public:
        //Variables Containing the Details of The student and the book being borrowed
        string Student_FirstName;
        string Student_LastName;
        string Student_ID;
        string Student_YearLevel;
        string Book_Category;
        string Bookname;
        string BookAuthor;
        string Book_Date_of_Borrow;
        string Book_Deadline_of_Borrow;
        // A unique ID for the borrowed book
        string Unique_ID;
        // Constructor for BorrowedBook_Information objects
        BorrowedBook_Information(   string &Student_FirstName, 
                                    string &Student_LastName, 
                                    string &Student_ID,
                                    string &Student_YearLevel,
                                    string &Book_Category,
                                    string &Bookname,
                                    string &BookAuthor,
                                    string &Book_Date_of_Borrow,
                                    string &Book_Deadline_of_Borrow,
                                    string &Unique_ID)
        {
            this->Student_FirstName = Student_FirstName;
            this->Student_LastName = Student_LastName;
            this->Student_ID = Student_ID;
            this->Student_YearLevel = Student_YearLevel;
            this->Book_Category = Book_Category;
            this->Bookname = Bookname;
            this->BookAuthor = BookAuthor;
            this->Book_Date_of_Borrow = Book_Date_of_Borrow;
            this->Book_Deadline_of_Borrow = Book_Deadline_of_Borrow;
            this->Unique_ID = Unique_ID;
        }                          
};

// Lists the borrowed books in the database
// sorting_mode determines how the books are sorted (e.g. by borrower's name, book name, etc.)
void ListStudents(int sorting_mode) 
{
    if (sorting_mode == 0) 
    {
    Clear_screen();
    cout << "-----------------Borrowed Books-----------------" << endl;
    ifstream book_database;
    book_database.open("Include/data/borrowedbooks.data");
    if (!book_database.is_open())
    {
        cout << "Database Not Found";
        cout << endl; system("pause");
    } 
    vector<BorrowedBook_Information> BorrowedBook_Database;
    string database_line;

    while (getline(book_database, database_line))
    {
        string Student_FirstName;
        string Student_LastName;
        string Student_ID;
        string Student_YearLevel;
        string Book_Category;
        string Bookname;
        string BookAuthor;
        string month_borrowed, day_borrowed, year_borrowed;
        string month_deadline, day_deadline, year_deadline;
        string Book_Date_of_Borrow;
        string Book_Deadline_of_Borrow;
        string Unique_ID;
        istringstream Data_Pull(database_line);
        Data_Pull >> Student_FirstName >> Student_LastName >> Student_ID >> Student_YearLevel >> Book_Category
        >> Bookname >> BookAuthor >> month_borrowed >> day_borrowed >> year_borrowed >> month_deadline >> day_deadline >> year_deadline >> Unique_ID;
        Book_Date_of_Borrow = month_borrowed + " " + day_borrowed + " " + year_borrowed;
        Book_Deadline_of_Borrow = month_deadline + " " + day_deadline + " " + year_deadline;
        BorrowedBook_Information Student_Information_and_Book_data(Student_FirstName, Student_LastName, Student_ID, Student_YearLevel, Book_Category, Bookname, BookAuthor, Book_Date_of_Borrow, Book_Deadline_of_Borrow, Unique_ID);
        BorrowedBook_Database.push_back(Student_Information_and_Book_data);
    }
        for (BorrowedBook_Information i : BorrowedBook_Database) 
        {
            print("STUDENT: " + i.Student_LastName + ", " + i.Student_FirstName, color_black, color_blue); 
            cout << "\n | ID: " << i.Student_ID << "\n | Year Level: " << i.Student_YearLevel << "\n | Book Category: " << i.Book_Category
            << "\n | Book Name: " << i.Bookname << "\n | Book Author: " << i.BookAuthor << "\n | Date of Borrow: " << i.Book_Date_of_Borrow << "\n | Deadline: " << i.Book_Deadline_of_Borrow << "\n | Unique_ID: " << i.Unique_ID << "\n" << endl;
        }

    } else if (sorting_mode == 1) {
        Clear_screen();
        cout << "-----------------Borrowed Books-----------------" << endl;
        // Open the borrowed books database
        ifstream book_database;
        book_database.open("Include/data/borrowedbooks.data");
        if (!book_database.is_open())
        {
            // If the database can't be opened, print an error message
            cout << "Database Not Found";
            cout << endl; system("pause"); // Pause the program
        } 
        // Create a vector to store the borrowed book information
        vector<BorrowedBook_Information> BorrowedBook_Database;
        // Read the borrowed books data from the database
        string database_line;

        while (getline(book_database, database_line))
        {
            // Parse the data for each book
            string Student_FirstName;
            string Student_LastName;
            string Student_ID;
            string Student_YearLevel;
            string Book_Category;
            string Bookname;
            string BookAuthor;
            string month_borrowed, day_borrowed, year_borrowed;
            string month_deadline, day_deadline, year_deadline;
            string Book_Date_of_Borrow;
            string Book_Deadline_of_Borrow;
            string Unique_ID;
            istringstream Data_Pull(database_line);
            
            // Extract the data for each book from the database line
            Data_Pull >> Student_FirstName >> Student_LastName >> Student_ID >> Student_YearLevel >> Book_Category
            >> Bookname >> BookAuthor >> month_borrowed >> day_borrowed >> year_borrowed >> month_deadline >> day_deadline >> year_deadline >> Unique_ID;
            
            // Format the borrowed date and deadline for each book
            Book_Date_of_Borrow = month_borrowed + " " + day_borrowed + " " + year_borrowed;
            Book_Deadline_of_Borrow = month_deadline + " " + day_deadline + " " + year_deadline;
            // Create a BorrowedBook_Information object for each book
            BorrowedBook_Information Student_Information_and_Book_data(Student_FirstName, Student_LastName, Student_ID, Student_YearLevel, Book_Category, Bookname, BookAuthor, Book_Date_of_Borrow, Book_Deadline_of_Borrow, Unique_ID);
            // Add the book to the vector
            BorrowedBook_Database.push_back(Student_Information_and_Book_data);

    }
        sort(BorrowedBook_Database.begin(), BorrowedBook_Database.end(), [](BorrowedBook_Information a, BorrowedBook_Information b) {return a.Student_LastName < b.Student_LastName;});
        // Loop through the vector and print the borrowed book information
        for (BorrowedBook_Information i : BorrowedBook_Database) 
        {
            // Print the information for each borrowed book
            print("STUDENT: " + i.Student_LastName + ", " + i.Student_FirstName, color_black, color_blue); 
            cout << "\n | ID: " << i.Student_ID << "\n | Year Level: " << i.Student_YearLevel << "\n | Book Category: " << i.Book_Category
            << "\n | Book Name: " << i.Bookname << "\n | Book Author: " << i.BookAuthor << "\n | Date of Borrow: " << i.Book_Date_of_Borrow << "\n | Deadline: " << i.Book_Deadline_of_Borrow << "\n | Unique_ID: " << i.Unique_ID << "\n" << endl;
        }
    }
}
