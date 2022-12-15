#pragma once
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <windows.h>
#include "Console_Integrated_Sounds.h"
#include "Console_Coloring_Header.h"
#include "NAVIGATION_GUI.h"
#include "List_Students_Function.h"
#include "Book_Recommended.h"
using namespace std;

void Clear_screen();
void Clear_screen() {system("cls");}
void Menu();


int User_Input_choice;
struct Input_student_with_book_data 
{
        char* Deadline_of_Transaction;
        char* date_borrowed;
        string Date_Today;
        string Deadline;
        string Student_firstname;
        string Student_lastname;
        string Student_ID;
        string Student_Course;
        string Student_YearLevel;
        string Borrowed_BookCategory;
        string Borrowed_BookName;
        string Borrowed_BookAuthor;
        string Borrowed_BookDate;
        void Get_Student_Name();
        void Insert_Data_to_Database();
        void Get_Student_Yearlevel();   
        void Get_Student_Course();
        void Get_BookCategory();
        void Get_Book();
        void Check_if_Information_is_right();
};
void Input_student_with_book_data::Get_Student_Name() 
{
    Clear_screen();
    cout << "Student Full Name: ";
    cin >> Student_firstname >> Student_lastname;
    cout << "Student ID: ";
    cin >> Student_ID; cout << endl;
    Get_Student_Yearlevel();
}
void Input_student_with_book_data::Get_Student_Yearlevel() 
{
    Clear_screen();
    cout << "\t\t\t----PICK YEAR LEVEL-----\n";
    cout << "\t\t\t[1] 1st year" << endl;
    cout << "\t\t\t[2] 2nd year" << endl;
    cout << "\t\t\t[3] 3rd year" << endl;
    cout << "\t\t\t[4] 4th year" << endl;
    print("\n\n\t\t\t Note:", color_black, color_blue);
    print(" Press the Key of your Choice!", color_black, color_cyan);

    int KEY_PRESS = _getch();
    switch (KEY_PRESS)
    {
    case INPUT1:
        Student_YearLevel = "1st_Year";
        break;
    case INPUT2:
        Student_YearLevel = "2nd_Year";
        break;
    case INPUT3:
        Student_YearLevel = "3rd_Year";
        break;
    case INPUT4:
        Student_YearLevel = "4th_Year";
        break;
    default:
        cout << "NO OPTION, TRY AGAIN\n";
        Get_Student_Yearlevel();
        break;
    }
    Get_Student_Course();   
}

void Input_student_with_book_data::Get_Student_Course() 
{
    Clear_screen();
    cout << "\t\t\t----PICK COURSE-----\n\n";
    cout << "\t\t\t[1] BSECE" << endl;
    cout << "\t\t\t[2] BSCpE" << endl;
    cout << endl;
    print("\n\n\t\t\t Note:", color_black, color_blue);
    print(" Press the Key of your Choice!", color_black, color_cyan);

    int KEY_PRESS = _getch();
    switch (KEY_PRESS)
    {
        case INPUT1:
            Student_Course = "BSECE";
            break;
        case INPUT2:
            Student_Course = "BSCpE";
            break;
        default:
            cout << "NO OPTION, TRY AGAIN\n";
            Get_Student_Course();
            break;
    }
    Get_BookCategory(); 
}

void Input_student_with_book_data::Get_BookCategory() 
{
    Clear_screen();
    cout << "\t\t\t----PICK BOOK CATEGORY-----\n";
    cout << "\t\t\t[1] MATHEMATICS"  << endl;
    cout << "\t\t\t[2] SCIENCE"      << endl;
    cout << "\t\t\t[3] ENGINEERING"  << endl;
    cout << endl;
    print("\n\n\t\t\t Note:", color_black, color_blue);
    print(" Press the Key of your Choice!", color_black, color_cyan);

    int KEY_PRESS = _getch();
    switch (KEY_PRESS)
    {
        case INPUT1:
            Borrowed_BookCategory = "MATHEMATICS";
            break;
        case INPUT2:
            Borrowed_BookCategory = "SCIENCE";
            break;
        case INPUT3:
            Borrowed_BookCategory = "ENGINEERING";
            break;
        default:
            cout << "NO OPTION, TRY AGAIN\n";
            Get_BookCategory();
            break;
    }
    Get_Book();
}
void Input_student_with_book_data::Get_Book() 
{
    Clear_screen();
    string Line_from_data;
    string Temp_Book_Pointer;
    cout << "BOOK NUMBER: ";
    cin >> Temp_Book_Pointer;

    ifstream Book_List;
    Book_List.open("Booklists.data");
    if (!Book_List.is_open()) 
    {
        cout << "Book List Database Not Found";
        cout << endl; system("pause");
    } 
    while(getline(Book_List, Line_from_data)) 
    {
        string  Book_Number_Code, 
                Book_Name_from_Database,
                Book_Author_from_Database,
                Book_Date_from_Database;

        istringstream Data_Pull(Line_from_data);
        Data_Pull >> Book_Number_Code >> Book_Name_from_Database >> Book_Author_from_Database >> Book_Date_from_Database;
        if (Temp_Book_Pointer == Book_Number_Code)
        {
            Borrowed_BookName = Book_Name_from_Database;
            Borrowed_BookAuthor = Book_Author_from_Database;
            Borrowed_BookDate = Book_Date_from_Database; 
            cout << "BOOK NAME: " << Borrowed_BookName << endl;
            cout << "BOOK AUTHOR: " << Borrowed_BookAuthor << endl;
            cout << "DATE OF RELEASE: " << Borrowed_BookDate << endl;
            print("\n\nENTER = YES  ", color_black, color_green);
            print(" ESCAPE = NO ", color_white, color_red);   
            int KEYBOARD_LISTENER = _getch();
                cout << "Is this the right book?: ";
                    switch (KEYBOARD_LISTENER) {
                        case ENT:
                            Book_List.close();
                            Check_if_Information_is_right();
                            break; 
                        case ESC:
                            Get_Book();
                            break; 
                        default:
                            print("No options! Try Again\n", color_white, color_red);
            }
        }  
    }
    Clear_screen();
    print("NO BOOK FOR CODE " + Temp_Book_Pointer + " IS FOUND..", color_white, color_red);
    FAILSOUND();
    cout << endl; system("PAUSE");
    Get_Book();
}


void Input_student_with_book_data::Check_if_Information_is_right() 
{
    Clear_screen();

    //----GET TIME NOW----------------------------------------------------------------------
    time_t Time_Now;
    time(&Time_Now);
    date_borrowed = ctime(&Time_Now);
    
    string day_now, time_now, month_now, date_now, year_now;
    istringstream Borrowed_Data_Pull(date_borrowed);
    Borrowed_Data_Pull >> day_now >> month_now >> date_now >> time_now >> year_now;
    Date_Today = month_now + " " + date_now + " " + year_now;
    //--------------------------------------------------------------------------------------

    //----GET DEADLINE----------------------------------------------------------------------
    time_t Deadline_Time_Get = time(0);
    tm* deadline = localtime(&Deadline_Time_Get); 
    deadline->tm_mday += 7;
    mktime(deadline); 
    Deadline_of_Transaction = asctime(deadline);

    string Deadline_day, Deadline_month, Deadline_date, Deadline_year, Deadline_time;
    istringstream Deadline_Data_Pull(Deadline_of_Transaction);
    Deadline_Data_Pull >> Deadline_day >> Deadline_month >> Deadline_date >> Deadline_time >> Deadline_year;
    Deadline = Deadline_month + " " + Deadline_date + " " + Deadline_year;
    //--------------------------------------------------------------------------------------



    print("------------STUDENT DETAILS------------\n\n", color_white, color_blue);
    cout << "Student Name: " << Student_firstname << " " << Student_lastname << endl;
    cout << "Student ID: " << Student_ID << endl;
    cout << "Student Year: " << Student_YearLevel << endl;
    cout << "Student Course: " << Student_Course << endl;
    print("\n\n------------BOOK DETAILS------------\n\n", color_white, color_blue);
    cout << "Book Name: " << Borrowed_BookName << endl;
    cout << "Book Catogory: " << Borrowed_BookCategory << endl;
    cout << "Book Author: " << Borrowed_BookAuthor << endl;
    cout << "Book Date: " << Borrowed_BookDate << endl;
    cout << "Date of Borrow: " << Date_Today << endl;
    cout << "Deadline: " << Deadline << endl;
    cout << "\nIs this the right book?: \n\n\n";
    print("ENTER = YES  ", color_black, color_green);
    print(" ESCAPE = NO ", color_white, color_red);   
    int KEYBOARD_LISTENER = _getch();
                    switch (KEYBOARD_LISTENER) {
                        case ENT:
                            Insert_Data_to_Database();
                            break; 
                        case ESC:
                            Menu();
                            break; 
                        default:
                            print("No options! Try Again\n", color_white, color_red);
            }
}
void Input_student_with_book_data::Insert_Data_to_Database() 
{   
    ofstream borrowedbook_database("borrowedbooks.data", ios::app);
    ofstream Book_used("Book_used.data", ios::app);
    ifstream myfile("borrowedbooks.data");
    string firstline; 
    getline(myfile,firstline);
    borrowedbook_database << Student_firstname << " " << Student_lastname     
    << " " << Student_ID << " " << Student_YearLevel 
    << " " << Borrowed_BookCategory <<  " " 
    << Borrowed_BookName << " " << Borrowed_BookAuthor << " " << Date_Today << " " << Deadline  << endl;
    print("\n\nSTUDENT ADDED TO DATABASE\n\n", color_black, color_green);
    borrowedbook_database.close();
    Book_used << Borrowed_BookName << endl;
    system("pause");
    Menu();
}

void Menu()     
{
        Clear_screen();
        while (true)
        {       
                Input_student_with_book_data BorrowedBook_data;
                Check_if_program_firstRun_menu(MENU_GUI_RECIEVER);
                int KEYBOARD_LISTENER = _getch();
                if (MENU_GUI_RECIEVER == 0) {
                        MENU_DIALOGUE_FIRST();
                        switch (KEYBOARD_LISTENER) {
                                case KB_UP:
                                        MENU_DIALOGUE_EXIT();
                                        MENU_GUI_RECIEVER = 4;
                                        break;   
                                case KB_DOWN:
                                        MENU_DIALOGUE_SECOND();
                                        MENU_GUI_RECIEVER = 1;
                                        break;   
                                case ENT:
                                        CONFIRMSOUND();
                                        MENU_GUI_RECIEVER = 12;
                                        BorrowedBook_data.Get_Student_Name();  
                                        break;   
                                default:
                                        break;
                        }
                } else if (MENU_GUI_RECIEVER == 1) {
                        switch (KEYBOARD_LISTENER) {
                                case KB_UP:
                                        MENU_DIALOGUE_FIRST();
                                        MENU_GUI_RECIEVER = 0;
                                        break;   
                                case KB_DOWN:
                                        MENU_DIALOGUE_THIRD();
                                        MENU_GUI_RECIEVER = 2;
                                        break;   
                                case ENT:
                                        CONFIRMSOUND();
                                        MENU_GUI_RECIEVER = 12;
                                        ListStudents();
                                        break;
                                default:
                                        break;
                        }
                } else if (MENU_GUI_RECIEVER == 2) {
                        switch (KEYBOARD_LISTENER) {
                                case KB_UP:
                                        MENU_DIALOGUE_SECOND();
                                        MENU_GUI_RECIEVER = 1;
                                        break;   
                                case KB_DOWN:
                                        MENU_DIALOGUE_FOURTH();
                                        MENU_GUI_RECIEVER = 3;
                                        break;   
                                case ENT:
                                        MENU_GUI_RECIEVER = 12;
                                        CONFIRMSOUND();
                                        break;
                                default:
                                        break;
                        }
                } else if (MENU_GUI_RECIEVER == 3) {
                        switch (KEYBOARD_LISTENER) {
                                case KB_UP:
                                        MENU_DIALOGUE_THIRD();
                                        MENU_GUI_RECIEVER = 2;
                                        break;   
                                case KB_DOWN:
                                        MENU_DIALOGUE_EXIT();
                                        MENU_GUI_RECIEVER = 4;
                                        break;   
                                case ENT:
                                        MENU_GUI_RECIEVER = 12;
                                        CONFIRMSOUND();
                                        Most_RecommendedBooks();
                                        break;
                                default:
                                        break;
                        }
                } else if (MENU_GUI_RECIEVER == 4) {
                        switch (KEYBOARD_LISTENER) {
                                case KB_UP:
                                        MENU_DIALOGUE_FOURTH();
                                        MENU_GUI_RECIEVER = 3;
                                        break;   
                                case KB_DOWN:
                                        MENU_DIALOGUE_FIRST();
                                        MENU_GUI_RECIEVER = 0;
                                        break;   
                                case ENT:
                                        Beep(500,600);
                                        Beep(400,500);
                                        Clear_screen();
                                        print("SHUTTING DOWN", color_white, color_red);
                                        cout << "\n"; system("PAUSE");
                                        exit(0);
                                        break;
                                default:
                                        break;
                        }
                }
        
        }
}