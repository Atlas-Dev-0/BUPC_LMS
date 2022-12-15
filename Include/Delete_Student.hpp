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


class Deletion_BorrowedBook_Information
{
    public:
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

void Delete_Student_by_ID(string UNIQUE_ID) {
    ifstream book_database;
    book_database.open("Include/data/borrowedbooks.data");
    if (!book_database.is_open())
    {
        cout << "Database Not Found";
        cout << endl; system("pause");
    } 

    vector<Deletion_BorrowedBook_Information> BorrowedBook_Database;
    vector<string> Data_pulled_from_database;
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
        Deletion_BorrowedBook_Information Student_Information_and_Book_data(Student_FirstName, Student_LastName, Student_ID, Student_YearLevel, Book_Category, Bookname, BookAuthor, Book_Date_of_Borrow, Book_Deadline_of_Borrow, Unique_ID);
        BorrowedBook_Database.push_back(Student_Information_and_Book_data);
        if (UNIQUE_ID != Unique_ID) {
            string data = Student_FirstName + " " + Student_LastName + " " + Student_ID + " " + Student_YearLevel + " " + Book_Category + " " + Bookname + " " + BookAuthor + " " + Book_Date_of_Borrow + " " + Book_Deadline_of_Borrow + " " + Unique_ID;        
            Data_pulled_from_database.push_back(data);
            break;
        }
        
    }   
    ofstream Clearing;
    Clearing.open("Include/data/borrowedbooks.data", ofstream::out | ofstream::trunc);
    string data_base_line2;
    ofstream borrowedbook_database_new("Include/data/borrowedbooks.data");
    ifstream book_database_new;
    book_database_new.open("Include/data/borrowedbooks.data");
    for (const string& line : Data_pulled_from_database) {
        borrowedbook_database_new << line << endl;
    }
}