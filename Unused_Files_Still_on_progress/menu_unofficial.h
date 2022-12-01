#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <windows.h>
#include "database.h"
using namespace std;


string firstname;
string lastname;
int id;
int choice;
string year_level;
string Student_program;
string Book_category;
string Bookname;
string Author;
vector<string> line23;
int number_of_lines = 0;

void getsizeandline();
void menu();
void addstudent();
void studentList();
void addheader();
void sortbylastname();
void sortbydateandday();
void sortbymonth();

//MainFrame
void addfileandheader() { 
    
}

void menu() {
    system("cls");
    cout << "\t\t\t-----WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM-----\n";
    cout << "\t\t\t\t[1] Add a borrow Book\n";
    cout << "\t\t\t\t[2] List of Students\n"; 
    cout << "\t\t\t\t[3] List of Books\n"; 
    cout << "\t\t\t\t[4] Show Top Recommended Books\n"; 
    cin >> choice;

    if (choice == 1) {
        addstudent();
    }
    else if (choice == 2) {
        studentList();
    }
    else if (choice == 3) {
        booklist();
    }
    else if (choice == 2) {
        RecommendedBooks();
    } else {
        cout << "No option, try again";
        menu();
    }
}

void addstudent() {
    system("cls");
    cout << "Student Full Name: ";
    cin >> firstname >> lastname;
    cout << "Student ID: ";
    cin >> id;
    cout << "\n";
    cout << "----PICK YEAR LEVEL-----\n";
    cout << "[1] 1st year" << endl;
    cout << "[2] 2nd year" << endl;
    cout << "[3] 3rd year" << endl;
    cout << "[4] 4th year" << endl;
    cout << "Year Level: ";
    cin >> choice;
    
    if(choice == 1) {
        year_level = "1st_Year";
    } else if(choice == 2) {
        year_level = "2nd_Year";
    } else if(choice == 3) {
        year_level = "3rd_Year";
    } else if(choice == 4) {
        year_level = "4th_Year";
    } else {
        cout << "No option, try again";
        addstudent();
    }
    cout << "\n";
    cout << "----PICK COURSE-----\n";
    cout << "[1] BSECE" << endl;
    cout << "[2] BSCpE" << endl;
    cout << "Student Program: ";
    cin >> choice;

    if(choice == 1) {
        Student_program = "BSECE";
    } else if(choice == 2) {
        Student_program = "BSCpE";
    } else {
        cout << "No option, try again";
        addstudent();
    }
    cout << "\n";
    cout << "----PICK BOOK CATEGORY-----\n";
    cout << "[1] MATHEMATICS" << endl;
    cout << "[2] SCIENCE" << endl;
    cout << "[3] ENGINEERING" << endl;
    cout << "Enter Book Category: ";
    cin >> choice;

    if(choice == 1) {
        Book_category = "MATHEMATICS";
    } else if(choice == 2) {
        Book_category = "SCIENCE";
    } else if(choice == 3) {
        Book_category = "ENGINEERING";
    } else {
        cout << "No option, try again";
        addstudent();
    }
    cout << "\n";
    cout << "Book Name: ";
    cin >> Bookname;

    cout << "Author: ";
    cin >> Author;

    time_t now;
    time(&now);
    char* dt = ctime(&now);

    
    ofstream borrowedbook_database("borrowedbooks.data", ios::app);
    ifstream myfile("borrowedbooks.data");
    string firstline;
    getline(myfile,firstline);
    if(firstline == "") {
        borrowedbook_database << "STUDENT WITH BORROWED BOOK LIST\n";
    } 
    borrowedbook_database << firstname << " " << lastname     
    << " " << id << " " << year_level 
    << " " << Book_category <<  " " 
    << Bookname << " " << Author << " " << dt;
    cout << "--------STUDENT ADDED TO DATABASE----------\n";
    system("pause");
    borrowedbook_database.close();
    menu();
    

};


void studentList() {
    ifstream myfile("borrowedbooks.data");
    system("cls");
    if (line23.size() <= 0 && number_of_lines == 0) {
        getsizeandline();
    } else { 
        cout << "\n\t\t\t\t\t\t\t--------------STUDENT LIST------------------\n";
        cout << "\n";

            for (int i = 0; i < number_of_lines-1; i++) {
                cout << line23.at(i) << endl;
                cout << "\n";
            } 
        cout << " \n\n\n";
        cout << "[1] SORT BY LASTNAME \t\t [2] SORT BY DATE AND TIME \t\t [3] SORT BY MONTH \t\t [4] EXIT \n ";
        cout << "Sort by: "; cin >> choice;
        myfile.close();
        switch (choice)
        {
            case 1:
                {
                     sortbylastname();
                    break;
                }
            case 2:
                {
                    sortbydateandday();
                    break;
                }
            case 3:
                {
                    sortbymonth();
                    break;
                }
            case 4:
                {
                    menu();
                    break;
                }
            default:
                {
                    cout<<"no such option";
                    studentList();
                }
        }
        /*if(choice == 4) {
            menu();
        } else {
            cout << "no such option";
            studentList();
        }*/
    }
}


void sortbylastname() {
}


void sortbydateandday(){
}


void sortbymonth(){
}


void getsizeandline() {
    system("cls");
    string firstname, lastname, id, yearlevel,bookcategory, bookname, bookauthor, day, month, date, time, year;
    string line;
    string output;
    ifstream myfile("borrowedbooks.data");
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,line);
            myfile >> firstname >> lastname >> id >> yearlevel >> bookcategory >> bookname >> bookauthor  >> day >> month >> date >> time >> year;
            output = "Name: " + firstname + " " + lastname
            + " | ID: " + id 
            + " | Year Level: " + yearlevel
            + " | Book Category: " + bookcategory 
            + " | Book Name: " + bookname 
            + " | Book Author: " + bookauthor
            + " | Date of borrow: " + day + " "
            + month + " " + date + " " + time + " " + year;
            line23.push_back(output);
            number_of_lines++;
        }
        myfile.close();
    } else {
        cout << "\nDATABASE EMPTY\n";
        system("pause");
        menu();
    }
    studentList();
}


