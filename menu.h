#include <iostream>
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



void menu();
void addstudent();
void studentList();



//MainFrame

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
        year_level = "1st Year";
    } else if(choice == 2) {
        year_level = "2nd Year";
    } else if(choice == 3) {
        year_level = "3rd Year";
    } else if(choice == 4) {
        year_level = "4th Year";
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

    ofstream swb("borrowedbookstry.data", ios::app);
    swb << firstname << " " << lastname 
    << " " << id << " " << year_level 
    << " " << Book_category <<  " " 
    << Bookname << " " << Author << " " << dt;
    cout << "--------STUDENT ADDED TO DATABASE----------\n";
    swb.close();

    system("pause");
    menu();

};

void getsizeandline();

void studentList() {
    system("cls");

    if (line23.size() <= 0 && number_of_lines == 0) {
        getsizeandline();
    } else { 
        cout << "\n\t\t\t--------------STUDENT LIST------------------\n";
        cout << "";

            for (int i = 0; i < number_of_lines-1; i++) {
                cout << line23.at(i) << endl;
                cout << "------------------------------------------------------------------------------\n";
            } 

        cout << "finished\n";
        system("pause");
        menu();
    }
    
    
}

void getsizeandline() {
    system("cls");
    string firstname, lastname, id, yearlevel,bookcategory, bookname, bookauthor, dt;
    string line;
    string output;
    ifstream myfile("borrowedbookstry.data");
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,line);
            myfile >> firstname >> lastname >> id >> yearlevel >> bookcategory >> bookname >> bookauthor  >> dt;
            output = "Name: " + firstname + " " + lastname
            + " | ID: " + id 
            + " | Year Level: " + yearlevel
            + " | Book Category: " + bookcategory 
            + " | Book Author: " + bookauthor
            + " | Date of borrow: " + dt;
            line23.push_back(output);
            number_of_lines++;
        }
        myfile.close();
    }
    studentList();
}



