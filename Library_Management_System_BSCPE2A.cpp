#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio>
#include <vector>
#include "Include/Console_Coloring_Header.h"
#include "Include/Navigation_guis.hpp"
#include "Include/Get_Student_List.hpp"
#include "Include/Delete_Student.hpp"
#include "Include/Borrow_ID_Generator.hpp"
#include "Include/Book_Recommended.hpp"

using namespace std;

struct Login_Menu_Class {
    int  User_Option;    
    void Login_Menu();
    void User_Login();
    void Registration_Form();
    void Forgot_Password_Form();
};

struct Book_Transaction 
{   
        int Category_Code;
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
        string Unique_ID;
        void Menu();
        void Data_reset();
        void Most_RecommendedBooks_menu();
        void Delete_Student();
        void Get_Student_List();
        void Get_Student_Name();
        void Get_Student_ID();
        void Get_Student_Yearlevel();   
        void Get_Student_Course();
        void Get_BookCategory();
        void Get_Book_Details();
        void Check_if_Information_is_right();
        void Insert_Data_to_Database();
        void ShowBooks(string File_Name);
        void ShowBooks_from_DataBase_for_BookNumber(string Unique_ID);
        void Get_List();
        int check_if_UNIQUE_ID_EXIST(string Unique_ID);
};



void Login_Menu_Class::Login_Menu() {

    while(true) {
        Book_Transaction Book_Transaction;
        Check_if_program_firstRun(LOGIN_GUI_RECIEVER);
        int KEYBOARD_LISTENER_2 = _getch();
        if (LOGIN_GUI_RECIEVER == 0) {
                LOGIN_DIALOGUE_FIRST();
                switch (KEYBOARD_LISTENER_2) {
                        case KB_UP:
                                LOGIN_DIALOGUE_EXIT(); 
                                LOGIN_GUI_RECIEVER = 3;
                                break;
                        case KB_DOWN:
                                LOGIN_DIALOGUE_SECOND();
                                LOGIN_GUI_RECIEVER = 1;
                                break;
                        case ENT:
                                CONFIRMSOUND();
                                LOGIN_GUI_RECIEVER = 12;
                                User_Login();
                                break;
                        case ACCSDEVMODE: 
                                CONFIRMSOUND();
                                LOGIN_GUI_RECIEVER = 12;
                                print("\n\n\t\t\tAccessing developer mode \n", color_green);
                                cout << "\t\t\t"; system("pause");
                                Book_Transaction.Menu();
                                break;  
                        default:
                                break;
                } 
        } else if (LOGIN_GUI_RECIEVER == 1) {
                LOGIN_DIALOGUE_SECOND();
                switch (KEYBOARD_LISTENER_2) {
                        case KB_UP:
                                LOGIN_DIALOGUE_FIRST(); 
                                LOGIN_GUI_RECIEVER = 0;
                                break;
                        case KB_DOWN:
                                LOGIN_DIALOGUE_THIRD();
                                LOGIN_GUI_RECIEVER = 2;
                                break;
                        case ENT:
                                CONFIRMSOUND();
                                LOGIN_GUI_RECIEVER = 12;
                                Registration_Form();
                                break;
                        case ACCSDEVMODE: 
                                CONFIRMSOUND();
                                LOGIN_GUI_RECIEVER = 12;
                                print("\n\n\t\t\tAccessing developer mode \n", color_green);
                                cout << "\t\t\t"; system("pause");
                                Book_Transaction.Menu();
                                break;  
                        default:
                                break;
                } 
        } else if (LOGIN_GUI_RECIEVER == 2) {
                LOGIN_DIALOGUE_THIRD();
                switch (KEYBOARD_LISTENER_2) {
                        case KB_UP:
                                LOGIN_DIALOGUE_SECOND(); 
                                LOGIN_GUI_RECIEVER = 1;
                                break;
                        case KB_DOWN:
                                LOGIN_DIALOGUE_EXIT();
                                LOGIN_GUI_RECIEVER = 3;
                                break;
                        case ENT: 
                                CONFIRMSOUND();
                                LOGIN_GUI_RECIEVER = 12;
                                Forgot_Password_Form();
                                break;
                        case ACCSDEVMODE: 
                                CONFIRMSOUND();
                                LOGIN_GUI_RECIEVER = 12;
                                print("\n\n\t\t\tAccessing developer mode \n", color_green);
                                cout << "\t\t\t"; system("pause");
                                Book_Transaction.Menu();
                                break;  
                        default:
                                break;
                } 
        } else if (LOGIN_GUI_RECIEVER == 3) {
                LOGIN_DIALOGUE_EXIT();
                switch (KEYBOARD_LISTENER_2) {
                        case KB_UP:
                                LOGIN_DIALOGUE_THIRD(); 
                                LOGIN_GUI_RECIEVER = 2;
                                break;
                        case KB_DOWN:
                                LOGIN_DIALOGUE_FIRST();
                                LOGIN_GUI_RECIEVER = 0;
                                break;
                        case ENT: 
                                Beep(500,600);
                                Beep(400,500);
                                Clear_screen();
                                print("SHUTTING DOWN", color_white, color_red);
                                cout << "\n"; system("PAUSE");
                                exit(0);
                                break;   
                        case ACCSDEVMODE: 
                                CONFIRMSOUND();
                                LOGIN_GUI_RECIEVER = 12;
                                print("\n\n\t\t\tAccessing developer mode \n", color_green);
                                cout << "\t\t\t"; system("pause");
                                Book_Transaction.Menu();
                                break;  
                        default:
                                break;
                }
        }
    }
}
void Login_Menu_Class::User_Login() {
        Book_Transaction Book_Transaction;
        int count = 3;
        while(count != 0) {
                Clear_screen(); 
                string Password ="";
                string  Username, 
                        InputID;
                string Line_from_data;
                print("\t\t\tTries Left: ", color_red);      
                cout << count; 
                print("\n\t\t\tInput \"exit\" or \"back\" to go back to Login Menu", color_red);
                cout << "\n\n";
                print("\n\n\t\t\tINPUT USERNAME AND PASSWORD ", color_black, color_blue);
                cout << endl;
                print("\t\t\t  USERNAME: ", color_light_blue);
                cin >> Username;
                if (Username == "back" || Username == "exit") {
                                Login_Menu();
                }
                print("\t\t\t  ID: ", color_light_blue);
                cin >> InputID;
                if (InputID == "back" || InputID == "exit") {
                                Login_Menu();;
                }
                char KEYBOARD;
                print("\t\t\t  PASSWORD: ", color_light_blue);
                KEYBOARD = _getch();
                
                while(KEYBOARD != 13){
                        if (KEYBOARD != 8) {
                                Password.push_back(KEYBOARD);
                                cout << '*';
                                KEYBOARD = _getch();
                        } else if (KEYBOARD == 8) {
                                User_Login();
                        }
                }

                if (Password == "back" || Password == "exit" ) {
                                Login_Menu();
                        }
                ifstream AccountData;
                AccountData.open("Include/data/AccountData.data");
                if (!AccountData.is_open()) 
                {
                        cout << "\nDatabase Not Found\n";
                        cout << endl; system("pause");
                }
                while (getline(AccountData, Line_from_data))
                {
                        string DataRegistered_USER;
                        string DataRegistered_ID;
                        string DataRegistered_PASS;

                        istringstream Data_Pull(Line_from_data);
                        Data_Pull >> DataRegistered_USER >> DataRegistered_ID >> DataRegistered_PASS;
                        if (Username == DataRegistered_USER && InputID == DataRegistered_ID && Password == DataRegistered_PASS) {

                                CONFIRMSOUND();
                                Clear_screen();
                                print("\n\t\t\tWELCOME BACK " + Username, color_black, color_green);
                                cout << "\n\t\t\t"; system("pause");
                                Book_Transaction.Menu();
                        } 
                }
                FAILSOUND();
                print("\n\t\t\tLOGIN ERROR\n", color_red); 
                cout << "\n\t\t\tplease check your username and password\n";
                cout << "\t\t\t"; system("pause");
                count--;
        }
}
void Login_Menu_Class::Registration_Form() {
	    
        string Input_from_user;
	vector<string> Input_Vector;
        system("cls");
        print("\n\n\n\t\t\tREGISTRATION: PLEASE INPUT THE INFORMATION ASKED!", color_white, color_blue);
        print("\n\t\t\tInput \"exit\" or \"back\" to go back to Login Menu", color_red);
        cout << "\n\n";
        cout << "\t\t\t Enter the username : ";
        cin >> Input_from_user;
        if (Input_from_user == "exit") {
                Login_Menu();
        }
        Input_Vector.push_back(Input_from_user);

        cout << "\t\t\t Enter the authentication ID : ";
        cin >> Input_from_user;
        if (Input_from_user == "exit") {
                Login_Menu();
        }
        Input_Vector.push_back(Input_from_user);

        string Line_from_Data;
        ofstream("Include/data/AccountData.data", ios::app);
        ifstream Account_Data;
        Account_Data.open("Include/data/AccountData.data");

        while(getline(Account_Data, Line_from_Data)) {
                string Username, ID, password;
                istringstream Data_Pull(Line_from_Data);
                Data_Pull >> Username >> ID >> password;
                if (Input_Vector[1] == ID) {
                        FAILSOUND();
                        print("\n\t\t\t AUTHENTICATION ID ALREADY REGISTERED!!", color_black, color_red);
                        cout << "\n\t\t\t"; system("pause");
                        system("cls");
                        Registration_Form();
                        break;
                } 
        }
        cout << "\t\t\t Enter the password : ";
        cin >> Input_from_user;
        if (Input_from_user == "exit") {
                Login_Menu();
        }
        Input_Vector.push_back(Input_from_user);

        cout << "\t\t\t Re-type the password : ";
        cin >> Input_from_user;
        if (Input_from_user == "exit") {
                Login_Menu();
        }
        Input_Vector.push_back(Input_from_user);

        if (Input_Vector[3] == Input_Vector[2]) {
                ofstream f1("Include/data/AccountData.data", ios::app);
                f1 << Input_Vector[0] << ' ' << Input_Vector[1] << ' ' << Input_Vector[2] << endl;
                GOODSOUND();
                print("\n\t\t\t Registration is successful!!", color_black, color_green);
                cout << "\n\t\t\t"; system("pause");
                Login_Menu();
        } else if (Input_Vector[3]!=Input_Vector[2]) {
                FAILSOUND();
                print("\n\t\t\t Enter the SAME PASSWORD!!", color_black, color_red);
                cout << "\n\t\t\t"; system("pause");
                Registration_Form();
        } else { 
                Login_Menu();
        }	
}
void Login_Menu_Class::Forgot_Password_Form()
{
	system("cls");
	print("\n\n\n\t\t\tPASSWORD RECOVERY\n\n", color_black, color_blue);
	print("\t\t\t[1]", color_black, color_cyan); 
	cout << " ";
	print("SEARCH BY IDENTIFICATION NUMBER\n", color_blue);
	print("\t\t\t[2]", color_black, color_cyan);
	cout << " ";
	print("GO BACK TO MAIN MENU\n", color_blue);
	
	print("\n\n\t\t\t Note:", color_black, color_blue);
        print(" Press the Key of your Choice!", color_black, color_cyan);

	int PRESSED_OPTION = _getch();
	switch (PRESSED_OPTION)
	{
		case INPUT1: 
		{
			CONFIRMSOUND();
			string REGISTERED_ID_FROM_DATABASE, USERNAME_FROM_DATA_BASE, PASSWORD_FROM_DATABASE, AUTH_ID_FROM_USER;
			system("cls");
			print("Enter the authentication ID which you remembered: ", color_blue);
			cin >> AUTH_ID_FROM_USER;

			while (true)
			{
				ifstream Data_Pull("Include/data/AccountData.data");
				Data_Pull >> USERNAME_FROM_DATA_BASE >> REGISTERED_ID_FROM_DATABASE >> PASSWORD_FROM_DATABASE;

				if (REGISTERED_ID_FROM_DATABASE == AUTH_ID_FROM_USER)
				{
					GOODSOUND();
					print("\n\n\n\t\t\tYour account is found! \n", color_black, color_green);
					cout << "\n\t\t\tYour password is: " << PASSWORD_FROM_DATABASE << endl;
					cout << "\t\t\t"; system("pause");
					Data_Pull.close();
					Forgot_Password_Form();
				}
				else 
				{
					FAILSOUND();
					print("\n\n\n\t\t\tSorry your account is not found! \n", color_white, color_red);
					cout << "\t\t\t"; system("pause");
					Forgot_Password_Form();
				}
				break;
			}	
			break;
		}
		case INPUT2:
		{	
			Login_Menu();
		}
		default: 
    		Forgot_Password_Form();
	}
}

//----------------------------------------MENU----------------------------------------

void Book_Transaction::Menu()     
{
    Clear_screen();
    while (true)
    {      
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
                            Get_Student_Name();  
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
                            Get_Student_List();
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
                            Get_List();
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
                            Most_RecommendedBooks_menu();
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

void Book_Transaction::Most_RecommendedBooks_menu() {
        Clear_screen();
        Most_RecommendedBooks();
        string Choice;
        cout << "[1] Go back   |    [2] Reset DataBase\n";
        cin >> Choice;
        if (Choice == "1") {

                Menu();

        } else if (Choice == "2") {

                Data_reset();

        }
}

void Book_Transaction::Data_reset() 
{
    string option;
    cout << "Reset DataBase? (Y/N)" << endl;
    cin >> option;

    if (option == "Y" || option == "y") {
        ofstream DELETION;
        DELETION.open("Include/data/Book_used.data", ofstream::out | ofstream::trunc);
        DELETION.close();
    } else if (option == "N" || option == "n"){
        Most_RecommendedBooks_menu();
    } else {
        cout << "NO OPTION, TRY AGAIN" << endl;
        Data_reset();
    }

}


//------------------------BOOK DATA INPUT TRANSACTION------------------------

void Book_Transaction::Get_Student_Name() {
    Clear_screen();
    cout << "Student Full Name: ";
    cin >> Student_firstname >> Student_lastname;
    if (Student_firstname == "exit" || Student_lastname == "exit") {
        Menu();
    }
    Get_Student_ID();
}

void Book_Transaction::Get_Student_ID() {
    Clear_screen();
    cout << "Student ID: ";
    cin >> Student_ID; cout << endl;
    if (Student_ID == "exit") {
        Menu();
    }
    Get_Student_Yearlevel();
}

void Book_Transaction::Get_Student_Yearlevel() {
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

void Book_Transaction::Get_Student_Course() 
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

void Book_Transaction::Get_BookCategory() 
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
            Category_Code = 200;
            break;
        case INPUT2:
            Borrowed_BookCategory = "SCIENCE";
            Category_Code = 300;
            break;
        case INPUT3:
            Borrowed_BookCategory = "ENGINEERING";
            Category_Code = 100;
            break;
        default:
            cout << "NO OPTION, TRY AGAIN\n";
            Get_BookCategory();
            break;
    }
    Get_Book_Details();
}
void Book_Transaction::Get_Book_Details()
{
    Clear_screen();
    string Data_Base_Opened;
    ifstream Book_List;
    if (Category_Code == 200) {
        Book_List.open("Include/data/MATHBOOKS.data");
        Data_Base_Opened = "MATHBOOKS.data";
        ShowBooks_from_DataBase_for_BookNumber("Include/data/MATHBOOKS.data");
    }else if (Category_Code == 300) {
        Book_List.open("Include/data/SCIENCEBOOKS.data");
        Data_Base_Opened = "SCIENCEBOOKS.data";
        ShowBooks_from_DataBase_for_BookNumber("Include/data/SCIENCEBOOKS.data");
    }else if (Category_Code == 100) {
        Book_List.open("Include/data/ENGINEERINGBOOKS.data");
        Data_Base_Opened = "ENGINEERINGBOOKS.data";
        ShowBooks_from_DataBase_for_BookNumber("Include/data/ENGINEERINGBOOKS.data");
    }

    if (!Book_List.is_open()) 
    {
        cout << "Book List Database Not Found";
        cout << endl; system("pause");
    }
    string Line_from_data;
    string Temp_Book_Pointer;
    print("\n\nBOOK NUMBER: ", color_black, color_green);
    cin >> Temp_Book_Pointer;

    if (Student_ID == "exit") {
        Menu();
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
                            Get_Book_Details();
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
    Get_Book_Details();
}
void Book_Transaction::Check_if_Information_is_right() 
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
    Unique_ID = generateRandomID();
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
    cout << "Code of Borrow: " <<  Unique_ID << endl;
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
void Book_Transaction::Insert_Data_to_Database() {   
    ofstream borrowedbook_database("Include/data/borrowedbooks.data", ios::app);
    ofstream Book_used("Include/data/Book_used.data", ios::app);
    ifstream myfile("Include/data/borrowedbooks.data");
    string firstline; 
    getline(myfile,firstline);
    borrowedbook_database << Student_firstname << " " << Student_lastname     
    << " " << Student_ID << " " << Student_YearLevel 
    << " " << Borrowed_BookCategory <<  " " 
    << Borrowed_BookName << " " << Borrowed_BookAuthor << " " << Date_Today << " " << Deadline << " " << Unique_ID  << endl;
    print("\n\nSTUDENT ADDED TO DATABASE\n\n", color_black, color_green);
    borrowedbook_database.close();
    Book_used << Borrowed_BookName << endl;
    system("pause");
    Menu();
}
void Book_Transaction::Get_Student_List() {
        
        ListStudents(0);
        string sorting_mode;
        cout << "\n\n\n[1] To Sort by names     |      [2] Delete Student      |       [3] exit        |       [R] Reset DataBase\n";
        cout << "INPUT: ";
        cin >> sorting_mode;
        if (sorting_mode == "1") {
                ListStudents(1);
                string Does_User_Go_Back;
                while (Does_User_Go_Back != "2") {
                cout << "\n\n\n[2] Back to default          |       [3] Delete Student          |       [R] Reset DataBase\n";
                cout << "INPUT: ";
                cin >> Does_User_Go_Back;
                if (Does_User_Go_Back == "2") {
                        Get_Student_List();
                        break;
                } else if (Does_User_Go_Back == "3") {
                        Delete_Student();
                } else if (Does_User_Go_Back == "R") {
                        ofstream Clearing;
                        Clearing.open("Include/data/borrowedbooks.data", ofstream::out | ofstream::trunc);
                        print("\nDATABASE CLEARED\n", color_white, color_red);
                        system("pause");
                } else {
                        print("\nNO OPTION! please try again\n", color_red); 
                }
                }
        }else if (sorting_mode == "2") {
                Delete_Student();
        } else if (sorting_mode == "3") {
                Menu();
        } else if (sorting_mode == "R") {
                ofstream Clearing;
                Clearing.open("Include/data/borrowedbooks.data", ofstream::out | ofstream::trunc);
                print("\nDATABASE CLEARED\n", color_white, color_red);
                system("pause");
        } else {
                print("\nNO OPTION! please try again\n", color_red); 
                system("pause");
                Get_Student_List();
        }
}

void Book_Transaction::Delete_Student() {
        string UNIQUE_CODE_GENERATED;
        print("ENTER UNIQUE ID: ", color_black, color_blue);
        cin >> UNIQUE_CODE_GENERATED;
        if (check_if_UNIQUE_ID_EXIST(UNIQUE_CODE_GENERATED) == 1) {
                print("USER ID FOUND, DELETION CONFIRM\n", color_green);
                system("pause");
                Delete_Student_by_ID(UNIQUE_CODE_GENERATED);
                Get_Student_List();
        } else if(check_if_UNIQUE_ID_EXIST(UNIQUE_CODE_GENERATED) == 0) {
                print("USER ID NOT FOUND, DELETION CAN'T PROCEED\n", color_red);
                system("pause");
                Get_Student_List();
                
        } else {

        }
}

int Book_Transaction::check_if_UNIQUE_ID_EXIST(string Inputted_Unique_ID) {

        string database_line;
        ifstream book_database;
        book_database.open("Include/data/borrowedbooks.data");
        vector<string> Registered_unique_ids; 
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
                string Unique_ID;
                istringstream Data_Pull(database_line);
                Data_Pull >> Student_FirstName >> Student_LastName >> Student_ID >> Student_YearLevel >> Book_Category
                >> Bookname >> BookAuthor >> month_borrowed >> day_borrowed >> year_borrowed >> month_deadline >> day_deadline >> year_deadline >> Unique_ID;
                Registered_unique_ids.push_back(Unique_ID);
        }

        if (find(Registered_unique_ids.begin(), Registered_unique_ids.end(), Inputted_Unique_ID) != Registered_unique_ids.end())
        {
                return 1;
        }
        else
        {
                
                return 0;
        }
        
}

//----------------------BOOK LIST----------------------
void Book_Transaction::Get_List()
{
    Clear_screen();
    while (true) 
    {
        Check_if_program_firstRun_books(BOOKLIST_GUI_RECIEVER);
        int KEYBOARD = _getch();
        if (BOOKLIST_GUI_RECIEVER == 0) {
            BOOKLIST_DIALOGUE_FIRST();
            switch (KEYBOARD) {
            case KB_UP:
                BOOKLIST_DIALOGUE_FOURTH();
                BOOKLIST_GUI_RECIEVER = 3;
                break;
            case KB_DOWN:
                BOOKLIST_DIALOGUE_SECOND();
                BOOKLIST_GUI_RECIEVER = 1;
                break;
            case ENT:
                CONFIRMSOUND();
                BOOKLIST_GUI_RECIEVER = 12;
                ShowBooks("Include/data/ENGINEERINGBOOKS.data");
                break;
            default:
                break;
            }
        } else if (BOOKLIST_GUI_RECIEVER == 1) {
            switch (KEYBOARD) {
            case KB_UP:
                BOOKLIST_DIALOGUE_FIRST();
                BOOKLIST_GUI_RECIEVER = 0;
                break;
            case KB_DOWN:
                BOOKLIST_DIALOGUE_THIRD();
                BOOKLIST_GUI_RECIEVER = 2;
                break;
            case ENT:
                CONFIRMSOUND();
                BOOKLIST_GUI_RECIEVER = 12;
                ShowBooks("Include/data/MATHBOOKS.data");
                break;
            default:
                break;
            }
        } else if (BOOKLIST_GUI_RECIEVER == 2) {
            switch (KEYBOARD) {
            case KB_UP:
                BOOKLIST_DIALOGUE_SECOND();
                BOOKLIST_GUI_RECIEVER = 1;
                break;
            case KB_DOWN:
                BOOKLIST_DIALOGUE_FOURTH();
                BOOKLIST_GUI_RECIEVER = 3;
                break;
            case ENT:
                CONFIRMSOUND();
                BOOKLIST_GUI_RECIEVER = 12;
                ShowBooks("Include/data/SCIENCEBOOKS.data");
                break;
            default:
                break;
            }
        } else if (BOOKLIST_GUI_RECIEVER == 3) {
            switch (KEYBOARD) {
            case KB_UP:
                BOOKLIST_DIALOGUE_THIRD();
                BOOKLIST_GUI_RECIEVER = 2;
                break;
            case KB_DOWN:
                BOOKLIST_DIALOGUE_FIRST();
                BOOKLIST_GUI_RECIEVER = 0;
                break;
            case ENT:
                CONFIRMSOUND();
                BOOKLIST_GUI_RECIEVER = 12;
                Menu();
                break;
            default:
                break;
            }

        }
    }
}

void Book_Transaction::ShowBooks(string File_Name) {
        Clear_screen();
        print ("BOOK LIST FROM DATABASE:", color_green);
        print (File_Name + "\n", color_green);
        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        ifstream file (File_Name, ios::in);
        if(file.is_open()) {
                while(getline(file, line)){
                        row.clear();
                        istringstream str(line);
                        while(getline(str, word, ','))
                        row.push_back(word);
                        content.push_back(row);
                }
        } else {
        cout<<"Could not open the file\n";
        }
        for(int i=0;i<content.size();i++) {
                for(int j=0;j<content[i].size();j++) {
                        cout<<content[i][j]<<" ";
                }
                cout<<"\n";
        }
        print ("\n\n[ESC] GO BACK", color_white, color_red);
        int INPUT = _getch();
        switch (INPUT)
        {
        case ESC:
                break;
        default:
                break;
        }
}


void Book_Transaction::ShowBooks_from_DataBase_for_BookNumber(string File_Name) {
        Clear_screen();
        print ("BOOK LIST FROM DATABASE:", color_green);
        print (File_Name + "\n", color_green);
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        ifstream file (File_Name, ios::in);
        if(file.is_open()) {
                while(getline(file, line)){
                        row.clear();
                        istringstream str(line);
                        while(getline(str, word, ','))
                        row.push_back(word);
                        content.push_back(row);
                }
        } else {
        cout<<"Could not open the file\n";
        }
        for(int i=0;i<content.size();i++) {
                for(int j=0;j<content[i].size();j++) {
                        cout<<content[i][j]<<" ";
                }
                cout<<"\n";
                }
}

int main() {
    //Program Starts by calling the Login_Menu()
    cout << setw(100) << setfill('-') << "\n";
    Login_Menu_Class Login_Menu_Class;
    Login_Menu_Class.Login_Menu();
    return 0;
}



