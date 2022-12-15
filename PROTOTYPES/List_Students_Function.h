#pragma once
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include "Console_Coloring_Header.h"
using namespace std;

void Clr_scrn();
void Clr_scrn() {system("cls");}

class BorrowedBook_Information
{
    public:
        string Student_FirstName;
        string Student_LastName;
        string Student_ID;
        string Student_YearLevel;
        string Bookname;
        string BookAuthor;
        string Book_Date_of_Borrow;
        string Book_Deadline_of_Borrow;

        BorrowedBook_Information(   string &Student_FirstName, 
                                    string &Student_LastName, 
                                    string &Student_ID,
                                    string &Student_YearLevel,
                                    string &Bookname,
                                    string &BookAuthor,
                                    string &Book_Date_of_Borrow,
                                    string &Book_Deadline_of_Borrow)
        {
            this->Student_FirstName = Student_FirstName;
            this->Student_LastName = Student_LastName;
            this->Student_ID = Student_ID;
            this->Student_YearLevel = Student_YearLevel;
            this->Bookname = Bookname;
            this->BookAuthor = BookAuthor;
            this->Book_Date_of_Borrow = Book_Date_of_Borrow;
            this->Book_Deadline_of_Borrow = Book_Deadline_of_Borrow;
        }

                            
};

void ListStudents() 
{
    Clr_scrn();
    cout << "-----------------Borrowed Books-----------------" << endl;
    ifstream book_database;
    book_database.open("borrowedbooks.data");
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
        string Bookname;
        string BookAuthor;
        string Book_Date_of_Borrow;
        string Book_Deadline_of_Borrow;
        istringstream Data_Pull(database_line);
        Data_Pull >> Student_FirstName >> Student_LastName >> Student_ID >> Student_YearLevel 
        >> Bookname >> BookAuthor >> Book_Date_of_Borrow >> Book_Deadline_of_Borrow;
        BorrowedBook_Information Student_Information_and_Book_data(Student_FirstName, Student_LastName, Student_ID, Student_YearLevel, Bookname, BookAuthor, Book_Date_of_Borrow, Book_Deadline_of_Borrow);
        BorrowedBook_Database.push_back(Student_Information_and_Book_data);

    }
    string SortBy;
    for (BorrowedBook_Information i : BorrowedBook_Database) 
    {
        print("STUDENT: " + i.Student_LastName + ", " + i.Student_FirstName, color_black, color_blue); 
        cout << "\n | ID: " << i.Student_ID << "\n | Year Level: " << i.Student_YearLevel 
        << "\n | Book Name: " << i.Bookname << "\n | Book Author: " << i.BookAuthor << "\n | Date of Borrow: " << i.Book_Date_of_Borrow << "\n | Deadline: " << i.Book_Deadline_of_Borrow << "\n" << endl;
    }

    cout << "\n\n" << "[1] Sort by Name" << "      [2] Sort by Date" << endl;
    cin >> SortBy;

    if (SortBy == "1") {
            Clr_scrn();
            cout << "-----------------Borrowed Books-----------------" << endl;
            sort(BorrowedBook_Database.begin(), BorrowedBook_Database.end(), [](BorrowedBook_Information a, BorrowedBook_Information b) {return a.Student_LastName < b.Student_LastName;});
            for (BorrowedBook_Information i : BorrowedBook_Database) 
            {
                print("STUDENT: " + i.Student_LastName + ", " + i.Student_FirstName, color_black, color_blue); 
                cout << "\n | ID: " << i.Student_ID << "\n | Year Level: " << i.Student_YearLevel 
                << "\n | Book Name: " << i.Bookname << "\n | Book Author: " << i.BookAuthor << "\n | Date of Borrow: " << i.Book_Date_of_Borrow << "\n | Deadline: " << i.Book_Deadline_of_Borrow << "\n" << endl;
            }
            cout << "\n\n" << "[<]Back To Default" << endl;
            cin >> SortBy;
            if (SortBy == "<") {
                ListStudents();
            }
    } else {
        system("pause");
  }

}
