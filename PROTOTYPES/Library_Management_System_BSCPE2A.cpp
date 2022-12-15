#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include "MainMenu_and_BookTransaction.h"
#include "RegistrationForm.h"
#include "Console_Coloring_Header.h"
#include "Console_Integrated_Sounds.h"
#include "NAVIGATION_GUI.h"
using namespace std;



void Registration();
void Forgot_Passwd();
void Menu(); 
void LOGIN_DIALOGUE();
int User_Option;

void Login()
{
        int count = 3;
        while(count != 0) {
                Clear_screen(); 
                string Password ="";
                string  Username, 
                        InputID;
                string Line_from_data;
                print("\t\t\tTries Left: ", color_red);      
                cout << count; 
                print("\n\n\t\t\tINPUT USERNAME AND PASSWORD ", color_black, color_blue);
                cout << endl;
                print("\t\t\t  USERNAME: ", color_light_blue);
                cin >> Username;
                if (Username == "back" || Username == "exit") {
                                LOGIN_DIALOGUE();
                        }
                print("\t\t\t  ID: ", color_light_blue);
                cin >> InputID;
                if (InputID == "back" || InputID == "exit") {
                                LOGIN_DIALOGUE();;
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
                                Login();
                        }
                }
                if (Password == "back" || Password == "exit" ) {
                                LOGIN_DIALOGUE();
                        }
                ifstream AccountData;
                AccountData.open("AccountData.data");
                if (!AccountData.is_open()) 
                {
                        cout << "Database Not Found";
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
                                Menu();
                        } 
                }
                FAILSOUND();
                print("\n\t\t\tLOGIN ERROR\n", color_red); 
                cout << "\n\t\t\tplease check your username and password\n";
                cout << "\t\t\t"; system("pause");
                count--;
        }
}
void LOGIN_DIALOGUE() 
{       
	Clear_screen();
        while(true) {
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
                                        Login();
                                        break;
                                case ACCSDEVMODE: 
                                        CONFIRMSOUND();
                                        LOGIN_GUI_RECIEVER = 12;
                                        print("\n\n\t\t\tAccessing developer mode \n", color_green);
                                        cout << "\t\t\t"; system("pause");
                                        Menu();
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
                                        Registration();
                                        break;
                                case ACCSDEVMODE: 
                                        CONFIRMSOUND();
                                        LOGIN_GUI_RECIEVER = 12;
                                        print("\n\n\t\t\tAccessing developer mode \n", color_green);
                                        cout << "\t\t\t"; system("pause");
                                        Menu();
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
                                        Forgot_Passwd();
                                        break;
                                case ACCSDEVMODE: 
                                        CONFIRMSOUND();
                                        LOGIN_GUI_RECIEVER = 12;
                                        print("\n\n\t\t\tAccessing developer mode \n", color_green);
                                        cout << "\t\t\t"; system("pause");
                                        Menu();
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
                                        Menu();
                                        break;  
                                default:
                                        break;
                        }
                }
        }
}
void Registration()
{
	string Input_from_user;
	vector<string> Input_Vector;
	
	
        system("cls");
        print("\n\n\n\t\t\tREGISTRATION: PLEASE INPUT THE INFORMATION ASKED!", color_white, color_blue);
        print("\n\t\t\tInput \"exit\" or \"back\" to go back to Login Menu", color_red);
        cout << "\n\n";
        cout << "\t\t\t Enter the username : ";
        cin >> Input_from_user;
        if (Input_from_user == "exit") {
                LOGIN_DIALOGUE();
        }
        Input_Vector.push_back(Input_from_user);

        cout << "\t\t\t Enter the authentication ID : ";
        cin >> Input_from_user;
        if (Input_from_user == "exit") {
                LOGIN_DIALOGUE();
        }
        Input_Vector.push_back(Input_from_user);

        string Line_from_Data;
        ifstream Account_Data;
        Account_Data.open("AccountData.data");

        while(getline(Account_Data, Line_from_Data)) {
                string Username, ID, password;
                istringstream Data_Pull(Line_from_Data);
                Data_Pull >> Username >> ID >> password;
                if (Input_Vector[1] == ID) {
                        FAILSOUND();
                        print("\n\t\t\t AUTHENTICATION ID ALREADY REGISTERED!!", color_black, color_red);
                        cout << "\n\t\t\t"; system("pause");
                        system("cls");
                        Registration();
                        break;
                } 
        }
                
        cout << "\t\t\t Enter the password : ";
        cin >> Input_from_user;
        if (Input_from_user == "exit") {
                LOGIN_DIALOGUE();
        }
        Input_Vector.push_back(Input_from_user);

        cout << "\t\t\t Re-type the password : ";
        cin >> Input_from_user;
        if (Input_from_user == "exit") {
                LOGIN_DIALOGUE();
        }
        Input_Vector.push_back(Input_from_user);

                if (Input_Vector[3] == Input_Vector[2]) {
                        ofstream f1("AccountData.data", ios::app);
                        f1 << Input_Vector[0] << ' ' << Input_Vector[1] << ' ' << Input_Vector[2] << endl;
                        GOODSOUND();
                        print("\n\t\t\t Registration is successful!!", color_black, color_green);
                        cout << "\n\t\t\t"; system("pause");
                        LOGIN_DIALOGUE();
                } else if (Input_Vector[3]!=Input_Vector[2]) {
                        FAILSOUND();
                        print("\n\t\t\t Enter the SAME PASSWORD!!", color_black, color_red);
                        cout << "\n\t\t\t"; system("pause");
                        Registration();
                } else { 
                        LOGIN_DIALOGUE();
                }	
	}


void Forgot_Passwd()
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
				ifstream Data_Pull("AccountData.data");
				Data_Pull >> USERNAME_FROM_DATA_BASE >> REGISTERED_ID_FROM_DATABASE >> PASSWORD_FROM_DATABASE;

				if (REGISTERED_ID_FROM_DATABASE == AUTH_ID_FROM_USER)
				{
					GOODSOUND();
					print("\n\n\n\t\t\tYour account is found! \n", color_black, color_green);
					cout << "\n\t\t\tYour password is: " << PASSWORD_FROM_DATABASE << endl;
					cout << "\t\t\t"; system("pause");
					Data_Pull.close();
					Forgot_Passwd();
				}
				else 
				{
					FAILSOUND();
					print("\n\n\n\t\t\tSorry your account is not found! \n", color_white, color_red);
					cout << "\t\t\t"; system("pause");
					Forgot_Passwd();
				}
				break;
			}	
			break;
		}
		case INPUT2:
		{	
			break;
		}
		default: 
			Forgot_Passwd();
	}

}
int main()      
{      
        Clear_screen();
        LOGIN_DIALOGUE();
        return 0;
        
}