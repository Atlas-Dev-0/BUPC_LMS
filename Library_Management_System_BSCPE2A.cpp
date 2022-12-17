#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
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
    void Password_Recovery();
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


class Password_Recover {
        public:
                string REGISTERED_ID_FROM_DATABASE;
                string PASSWORD_FROM_REG_ID_IN_DATABASE;
                Password_Recover (string &REGISTERED_ID_FROM_DATABASE, string &PASSWORD_FROM_REG_ID_IN_DATABASE) {
                        this->PASSWORD_FROM_REG_ID_IN_DATABASE = PASSWORD_FROM_REG_ID_IN_DATABASE;
                        this->REGISTERED_ID_FROM_DATABASE = REGISTERED_ID_FROM_DATABASE;
                }

};

void Login_Menu_Class::Login_Menu() {

        /**--PARAGRAPH COMMENT--
         * This function is the main menu for logging in to the system. It displays a list of options for the user to choose from, such as logging in, registering, or recovering a forgotten password. 
         * It also includes a developer mode option, which allows the user to access the main program directly. 
         * The function also includes a keyboard listener that allows the user to navigate through the menu using the arrow keys.
         */

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

        /** --PARAGRAPH COMMENT---
        *This code is a member function of the Login_Menu_Class structure. It handles the process of logging in to the library management system. 
        *The function prompts the user to enter their username, ID, and password. It then checks if the entered credentials match those of a registered user by looking up the data in a file called AccountData.data.
        *The while loop at the beginning of the function allows the user to have up to three attempts to enter the correct credentials. 
        *The Clear_screen() function is called to clear the console screen before each attempt.
        *The user is then prompted to enter their username and ID. The input is stored in the Username and InputID variables, respectively. 
        *If the user enters "back" or "exit", the Login_Menu() function is called to return to the main login menu.
        *The user is then prompted to enter their password. The password is hidden as the user types by using the _getch() function to get each character from the keyboard without displaying it on the screen. 
        *The characters are then added to the Password string. If the user enters "back" or "exit" as the password, the Login_Menu() function is called to return to the main login menu.
        *The entered username, ID, and password are then checked against the registered user data in the AccountData.data file. 
        *If a match is found, the user is granted access to the main menu of the library management system. If no match is found, the user is informed of the login error and given another attempt. 
        *If the user exhausts all attempts, the function ends.
        */
        Book_Transaction Book_Transaction;
        int count = 3;
        while(count != 0) {
                Clear_screen(); 
                string Password ="";
                string  Username, 
                        InputID;
                string Line_from_data;
                print("\t\t\tTries Left: ", color_green);      
                cout << count; 
                print("\n\t\t\tInput \"exit\" or \"back\" to go back to Login Menu", color_red);
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

	//This function is the Registration_Form function of the Login_Menu_Class. It is used for registering a new user for the system. 
        string Input_from_user;
	vector<string> Input_Vector;
        system("cls");
        print("\n\n\n\t\t\tREGISTRATION: PLEASE INPUT THE INFORMATION ASKED!", color_white, color_blue);
        print("\n\t\t\tInput \"exit\" or \"back\" to go back to Login Menu", color_red);
        cout << "\n\n";
        //The function first prompts the user for a username, authentication ID, and password. 
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

        //It then checks if the entered authentication ID is already registered by reading from the AccountData.data file. 
        string Line_from_Data;
        ofstream("Include/data/AccountData.data", ios::app);
        ifstream Account_Data;
        Account_Data.open("Include/data/AccountData.data");

        while(getline(Account_Data, Line_from_Data)) {
                string Username, ID, password;
                istringstream Data_Pull(Line_from_Data);
                Data_Pull >> Username >> ID >> password;
                if (Input_Vector[1] == ID) {
                        //If the authentication ID is already registered or if the passwords don't match, the function will display an error message and prompt the user to try again. 
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

        //If the ID is not registered, the function will prompt the user to re-enter their password to confirm it, and if the passwords match, the function will add the new user's data to the AccountData.data file. 
        //The function will also return to the login menu if the user inputs "exit" or "back" at any point.
        cout << "\t\t\t Re-type the password : ";
        cin >> Input_from_user;
        if (Input_from_user == "exit") {
                Login_Menu();
        }
        Input_Vector.push_back(Input_from_user);
        //The function will check if the Input_vector[3] and [2] are the same which are the inputted passwords by the user
        if (Input_Vector[3] == Input_Vector[2]) {
                //If the Inputs are the same, then the it will prompt that the Registration is Successful
                ofstream f1("Include/data/AccountData.data", ios::app);
                f1 << Input_Vector[0] << ' ' << Input_Vector[1] << ' ' << Input_Vector[2] << endl;
                GOODSOUND();
                print("\n\t\t\t Registration is successful!!", color_black, color_green);
                cout << "\n\t\t\t"; system("pause");
                Login_Menu();
        } else if (Input_Vector[3]!=Input_Vector[2]) {
                //If the Inputs are the not the same, then the it will prompt that the Registration is unsuccessful
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
        //This C++ function is called Forgot_Password_Form, and it is a member of the Login_Menu_Class class
        Login_Menu_Class Login_Menu_Class;
	//When this function is called, it first clears the screen. 
        Clear_screen();
        //It then outputs a header message, followed by two options to either search by ID number or to go back to the main menu.
	print("\n\n\n\t\t\tPASSWORD RECOVERY\n\n", color_black, color_blue);
	print("\t\t\t[1]", color_black, color_cyan); 
	cout << " ";
	print("SEARCH BY IDENTIFICATION NUMBER\n", color_blue);
	print("\t\t\t[2]", color_black, color_cyan);
	cout << " ";
	print("GO BACK TO MAIN MENU\n", color_blue);
        //The function prompts the user to press the key of their choice, and then waits for user input.
	print("\n\n\t\t\t Note:", color_black, color_blue);
        print(" Press the Key of your Choice!", color_black, color_cyan);

	int PRESSED_OPTION = _getch();
	switch (PRESSED_OPTION)
	{
		case INPUT1: 
		{
                        // If the user presses the first option, the function calls the Password_Recovery function
			CONFIRMSOUND();
			Login_Menu_Class.Password_Recovery();
			break;
		}
		case INPUT2:
		{	
                        //If the user presses the second option, the function calls the Login_Menu function.
			Login_Menu_Class.Login_Menu();
		}
		default: 
                //If the user enters any other input, the function will call itself again, effectively looping back to the beginning.
    		Forgot_Password_Form();
	}
}


void Login_Menu_Class::Password_Recovery() {
        //The part of the code defines a function named "Password_Recovery" that belongs to a class called "Login_Menu_Class".
        string REGISTERED_ID_FROM_DATABASE, USERNAME_FROM_DATA_BASE, PASSWORD_FROM_DATABASE, AUTH_ID_FROM_USER;
        //The function first clears the screen and prompts the user to enter their authentication ID. 
        Clear_screen();
        print("Enter the authentication ID which you remembered: ", color_blue);
        cin >> AUTH_ID_FROM_USER;
        // The function retrieves a password associated with an authentication ID entered by the user. 
        //Then, it creates an empty vector with the template argument list of "Password_Recover" objects and opens an input stream on the file "Include/data/AccountData.data". 
        vector<Password_Recover> Registered_ID;
        ifstream Account_Data("Include/data/AccountData.data");
        string Data_line;
        //The function then reads the data file line by line, parsing the lines into username, authentication ID, and password, and creating a "Password_Recover" object with the authentication ID and password. 
        while (getline(Account_Data,Data_line))
        {       
                istringstream Data_Pull(Data_line);
                Data_Pull >> USERNAME_FROM_DATA_BASE >> REGISTERED_ID_FROM_DATABASE >> PASSWORD_FROM_DATABASE;
                Password_Recover Data_Pulled(REGISTERED_ID_FROM_DATABASE, PASSWORD_FROM_DATABASE);
                //The function adds each "Password_Recover" object to the vector.
                Registered_ID.push_back(Data_Pulled);
        }	
        // Then, the function searches the vector for an object with the authentication ID entered by the user. 
        for (Password_Recover i : Registered_ID) {
                if (AUTH_ID_FROM_USER == i.REGISTERED_ID_FROM_DATABASE)
                {
                        //If it finds a match, it outputs the password associated with the authentication ID and prompts the user to go back to the forgot password form.
                        GOODSOUND();
                        print("\n\n\n\t\t\tYour account is found! \n", color_black, color_green);
                        cout << "\n\t\t\tYour password is: " << i.PASSWORD_FROM_REG_ID_IN_DATABASE << endl;
                        cout << "\t\t\t"; system("pause");
                        Account_Data.close();
                        Forgot_Password_Form();
                        Registered_ID.clear();
                }
                else { }
        } 
        //If it does not find a match, it outputs an error message and prompts the user to go back to the forgot password form. 
        FAILSOUND();
        print("\n\n\n\t\t\tSorry your account is not found! \n", color_white, color_red);
        cout << "\t\t\t"; system("pause");
        Forgot_Password_Form();
        //Finally, the function clears the vector of "Password_Recover" objects.
        Registered_ID.clear();
}
//----------------------------------------MENU----------------------------------------

void Book_Transaction::Menu()     
{
    Clear_screen();
    while (true)
    {      
        /**
         * This code defines a function called Book_Transaction::Menu() that is part of the Book_Transaction class. The function displays a menu to the user and listens for keyboard input. 
         * The function has a while loop that will continue to run until the user decides to exit the program.
         * The Clear_screen() function is called at the beginning of the while loop to clear the screen and prepare it for the menu. The Check_if_program_firstRun_menu() function is called with the MENU_GUI_RECIEVER variable as an argument. This function checks if the program is being run for the first time, and if it is, it will display a message to the user.
         * The _getch() function is called to listen for keyboard input from the user. 
         * This function returns the ASCII value of the key that was pressed by the user. The returned value is stored in the KEYBOARD_LISTENER variable.The code then uses a series of if and switch statements to handle the different keyboard inputs that the user may make. Depending on the value of the KEYBOARD_LISTENER variable, different actions will be taken. For example, if the user presses the up arrow key (KB_UP), the MENU_DIALOGUE_EXIT() function will be called and the MENU_GUI_RECIEVER variable will be set to 4.
         * The different switch statements in the code handle different cases for the values of the KEYBOARD_LISTENER variable. For example, if KEYBOARD_LISTENER is KB_UP, the code will call the MENU_DIALOGUE_FIRST() function and set the value of MENU_GUI_RECIEVER to 0. If KEYBOARD_LISTENER is KB_DOWN, the code will call the MENU_DIALOGUE_SECOND() function and set the value of MENU_GUI_RECIEVER to 1. 
         * And if KEYBOARD_LISTENER is ENT (the Enter key), the CONFIRMSOUND() function will be called, the MENU_GUI_RECIEVER variable will be set to 12, and the Get_Student_Name() function will be called.
         * The function also includes else if statements to handle additional cases for the values of the KEYBOARD_LISTENER variable. For example, if MENU_GUI_RECIEVER is 1 and KEYBOARD_LISTENER is ENT, the code will call the Get_Student_List() function. And if MENU_GUI_RECIEVER is 4 and KEYBOARD_LISTENER is ENT, the code will call the Beep() function twice to produce a beep sound, clear the screen, print a message to the user, and then exit the program.
         */

        //this menu type of format can be seen and will be seen throughout the code as it is the basis for how the Navigation Illusion works or the GUI illusion works in the console, using the GUIS inside the Navigation header, we were able to create such an illusion.
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
        //This code basically calls a void from the header "Book_Recommended.hpp" and that function will list the most used books via usage in a descending order
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
    //The Data_reset function clears the data inside the ".data" file and clears it using the ofstream::trunc syntax
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
string Capitalize(string str) {

    //The Capitalize return function returns a given parameter of string as its capitalized form
    //The function will first break down the string as characters, and using the "isalpha" from the ctype header, we can return if the character is a letter or not
    //Once The isalpha returns 0, it means that the character from the broken down string is not a letter type
    //But once the isalpha returns 1, it continues to use the toupper() function that is also from the ctype header and turns it into a Capitalized Letter
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
    //Once the function is done, the return type function will return the string as a captalized function
    return str;
}
void Book_Transaction::Get_Student_Name() {
    //Get_Student_Name gets the FirstName from the user with the LastName
    Clear_screen();
    print("Example: John_Kenneth Gonzales\n\n", color_green);
    string FirstName, LastName;
    cout << "Student Full Name: ";
    cin >> FirstName >> LastName;
    if (Student_firstname == "exit" || Student_lastname == "exit") {
        Menu();
    }
    //The function will then declare the Student_firstname and Student_lastname strings from the Book_Transaction class as the Capitalized form of the inpuuted data from the user
    Student_firstname = Capitalize(FirstName);
    Student_lastname = Capitalize(LastName);
    //Then it will go to the next function
    Get_Student_ID();
}

void Book_Transaction::Get_Student_ID() { 
    //The Get_Student_ID() gets the ID from the user
    Clear_screen();
    cout << "Student ID: ";
    cin >> Student_ID; cout << endl;
    if (Student_ID == "exit") {
        Menu();
    }
    //Then it will go to the next function
    Get_Student_Yearlevel();
}

void Book_Transaction::Get_Student_Yearlevel() {
    //The Get_Student_Yearlevel() function gets the year level of the student using keyboard listener "_getch()" that is declared as int KEY_PRESS
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
    //Then it will go to the next function
    Get_Student_Course();
}

void Book_Transaction::Get_Student_Course() 
{
    //This function then picks the Student Course via Keyboard listener again
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
    //Then goes to the next function
    Get_BookCategory(); 
}

void Book_Transaction::Get_BookCategory() 
{
    //The Get_BookCategory is essential to the next function as it will define what books will be listed for the user to input it correctly by making the program prompt a list of books based from the category picked
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
    
    /**
     * This is defining a function called Book_Transaction::Get_Book_Details(), which is a member function of the Book_Transaction class. 
     * The function is used for retrieving details of a book from a database, based on the Category_Code and Book_Number_Code of the book. 
     * The function first opens one of three databases (MATHBOOKS, SCIENCEBOOKS, or ENGINEERINGBOOKS) based on the Category_Code. 
     * It then uses the ShowBooks_from_DataBase_for_BookNumber function to display all the books in the database.
     */
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

    /**
     * The function then prompts the user to enter the Book_Number_Code of the book they are looking for. 
     * If the user enters the keyword "exit", the Menu() function is called and the current function is exited. 
     * Otherwise, the function reads each line of the database file and parses the data using an istringstream object. 
     * If the Book_Number_Code entered by the user matches the Book_Number_Code of a book in the database, the function retrieves the Book_Name, Book_Author, and Book_Date for that book and displays them to the user.
     */
    string Line_from_data;
    string Temp_Book_Pointer;
    print("\n\nBOOK NUMBER: ", color_black, color_green);
    cin >> Temp_Book_Pointer;
    if (Temp_Book_Pointer == "exit") {
        Menu();
    }
    //Creates a loop that get lines from the Book_List data that is opened
    while(getline(Book_List, Line_from_data)) 
    {
        string  Book_Number_Code, 
                Book_Name_from_Database,
                Book_Author_from_Database,
                Book_Date_from_Database;
        //Using istringstream, the function will extract Data from the .data file that is loaded 
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

            /**
             * Finally, the function prompts the user to confirm whether the displayed book is the correct one by pressing the ENT or ESC key. 
             * If the user presses ENT, the Check_if_Information_is_right() function is called. 
             * If the user presses ESC, the Get_Book_Details() function is called again, allowing the user to enter a new Book_Number_Code. 
             * If the user presses any other key, an error message is displayed and the function is called again.
             */

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
    /**
     * This is a function called Book_Transaction::Check_if_Information_is_right(), which is a member function of the Book_Transaction class. 
     * The function is used for displaying the details of a book and a student who is borrowing the book, and then confirming whether the information is correct.
     * The function first clears the screen using the Clear_screen() function. 
     * It then retrieves the current date and time using the time() and ctime() functions, and parses the date and time into separate day, month, date, and year variables. 
     * The function then calculates the deadline for returning the borrowed book by adding 7 days to the current date, and then parses the deadline date into separate day, month, date, and year variables.
     */
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

    /**
     * The function then displays the details of the student and the book, including the student's name, ID, year level, and course; 
     * the book's name, category, author, and date of release; the date the book was borrowed; the deadline for returning the book; and a unique ID for the borrow transaction.
     */
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

    /**
     * Finally, the function prompts the user to confirm whether the displayed information is correct by pressing the ENT or ESC key. 
     * If the user presses ENT, the Insert_Data_to_Database() function is called. If the user presses ESC, the Menu() function is called. 
     * If the user presses any other key, an error message is displayed and the function is called again.
     */
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
        /**
         * Then simply ready the data by using the ifstream function borrowedbooks.data.
         */
    ofstream borrowedbook_database("Include/data/borrowedbooks.data", ios::app);
    ofstream Book_used("Include/data/Book_used.data", ios::app);
    ifstream myfile("Include/data/borrowedbooks.data");
    string firstline; 
    getline(myfile,firstline);
    /**
     * This function then display the data that has been stored to the ofstream function and other data from other void functions. 
     */
    borrowedbook_database << Student_firstname << " " << Student_lastname     
    << " " << Student_ID << " " << Student_YearLevel 
    << " " << Borrowed_BookCategory <<  " " 
    << Borrowed_BookName << " " << Borrowed_BookAuthor << " " << Date_Today << " " << Deadline << " " << Unique_ID  << endl;
    print("\n\nSTUDENT ADDED TO DATABASE\n\n", color_black, color_green);
    borrowedbook_database.close();
    /**
    *After displaying given data, the ofstream now close and return to the void Menu function.
    */
    Book_used << Borrowed_BookName << endl;
    system("pause");
    Menu();
}
void Book_Transaction::Get_Student_List() {
        /**
         *This function displays the student's list that has been stored that can be arranged to sorted by number or alphabetical order.
        */
        ListStudents(0);
        string sorting_mode;
        cout << "\n\n\n[1] To Sort by names     |      [2] Delete Student      |       [3] exit        |       [R] Reset DataBase\n";
        cout << "INPUT: ";
        cin >> sorting_mode;
        /*
                *This if condition will listen to what the user will input based from the printed options
        */
        if (sorting_mode == "1") {
                //Within the first loop will be a nested loop that propmts the user if he/she wants to go back to default, as well one of the first options which are number 3 and R
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
        //This function essentially checks if the unique ID that is inputted by the user exists by scraping through the borrwedbooks.data
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
                //It pulls the data using istring stream and breaks it down into the different string variables
                Data_Pull >> Student_FirstName >> Student_LastName >> Student_ID >> Student_YearLevel >> Book_Category
                >> Bookname >> BookAuthor >> month_borrowed >> day_borrowed >> year_borrowed >> month_deadline >> day_deadline >> year_deadline >> Unique_ID;
                //Then the function pushes back the unique Id 
                Registered_unique_ids.push_back(Unique_ID);
        }
        //The function will scrape the vector seeing if the Inputted_Unique_ID exists
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
        //This function Show Books that it extracts from the Databases that is inside the Include/data Folder
        Clear_screen();
        print ("BOOK LIST FROM DATABASE:", color_green);
        print (File_Name + "\n", color_green);
        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        ifstream file (File_Name, ios::in);
        //It first loops through the file using while loop that is nested into an if statement
        //Then the nested while loop will push back the line that was pulled in the data to the vectors content and row
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
        //Just like the ShowBooks() function, this prints the list of books from the database given in the parameter (string File_Name)
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



