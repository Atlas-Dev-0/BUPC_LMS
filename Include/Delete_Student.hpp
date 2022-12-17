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


// Deletion_BorrowedBook_Information class
// Contains information about a student and the book they borrowed
class Deletion_BorrowedBook_Information
{
    public:
    // Data members for student information and borrowed book details
        string Student_FirstName;
        string Student_LastName;
        string Student_ID;
        string Student_YearLevel;
        string Book_Category;
        string Bookname;
        string BookAuthor;
        string Book_Date_of_Borrow;
        string Book_Deadline_of_Borrow;
        string Unique_ID;

        // Constructor for Deletion_BorrowedBook_Information class
        // Initializes data members with provided information
        Deletion_BorrowedBook_Information(   
                                    string &Student_FirstName, 
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

// Deletes a student's borrowed book information from the database
// using the provided unique ID

void Delete_Student_by_ID(string UNIQUE_ID) {
     // Open borrowed books database
    ifstream book_database;
    book_database.open("Include/data/borrowedbooks.data");
    // Check if database was found
    if (!book_database.is_open())
    {
        // Print error message and pause program
        cout << "Database Not Found";
        cout << endl; system("pause");
    } 

    // Vector for storing student information and borrowed book details
    vector<Deletion_BorrowedBook_Information> BorrowedBook_Database;
    // Vector for storing data pulled from database
    vector<string> Data_pulled_from_database;
    // String for holding each line from database
    string database_line;

    while (getline(book_database, database_line))
    {
        // Variables for storing student information and borrowed book details
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
        
        // Parse line from database into individual data values
        istringstream Data_Pull(database_line);
        Data_Pull >> Student_FirstName >> Student_LastName >> Student_ID >> Student_YearLevel >> Book_Category
        >> Bookname >> BookAuthor >> month_borrowed >> day_borrowed >> year_borrowed >> month_deadline >> day_deadline >> year_deadline >> Unique_ID;
        
        // Format date and deadline values
        Book_Date_of_Borrow = month_borrowed + " " + day_borrowed + " " + year_borrowed;
        Book_Deadline_of_Borrow = month_deadline + " " + day_deadline + " " + year_deadline;
        
        // Create Deletion_BorrowedBook_Information object with parsed data
        Deletion_BorrowedBook_Information Student_Information_and_Book_data(Student_FirstName, Student_LastName, Student_ID, Student_YearLevel, Book_Category, Bookname, BookAuthor, Book_Date_of_Borrow, Book_Deadline_of_Borrow, Unique_ID);
        // Add object to BorrowedBook_Database vector
        BorrowedBook_Database.push_back(Student_Information_and_Book_data);
        
        // If provided unique ID does not match this line's unique ID
        // add this line's data to Data_pulled_from_database vector
        if (UNIQUE_ID != Unique_ID) {
            // Create string with data values
            string data = Student_FirstName + " " + Student_LastName + " " + Student_ID + " " + Student_YearLevel + " " + Book_Category + " " + Bookname + " " + BookAuthor + " " + Book_Date_of_Borrow + " " + Book_Deadline_of_Borrow + " " + Unique_ID;        
            // Add string objects to the vector
            Data_pulled_from_database.push_back(data);
        }
        
    }   
    // Clears the contents of the file "Include/data/borrowedbooks.data"
    // Open the file in write mode and truncate its contents
    ofstream Clearing;
    Clearing.open("Include/data/borrowedbooks.data", ofstream::out | ofstream::trunc);
    // Create a new file with the same name
    string data_base_line2;
    ofstream borrowedbook_database_new("Include/data/borrowedbooks.data");
    // Write the contents of Data_pulled_from_database to the new file, one line at a time
    ifstream book_database_new;
    book_database_new.open("Include/data/borrowedbooks.data");
    for (const string& line : Data_pulled_from_database) {
        borrowedbook_database_new << line << endl;
    }
}