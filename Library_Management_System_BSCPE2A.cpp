#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include "Book_Transaction.h"
#include "RegistrationForm.h"
#include "List_Students_Function.h"
#include "Console_Coloring_Header.h"
#include "Console_Integrated_Sounds.h"
#include "NAVIGATION_GUI.h"
using namespace std;

void Menu(); 
void LOGIN_DIALOGUE();

//KEYBOARD LISTENER-------------------------------
const int KB_UP = 72; 
const int KB_DOWN = 80;
const int KB_RIGHT = 77;
const int KB_LEFT = 75;
const int ENT = 13;
const int ESC = 27;
const int INPUT1 = 49; 
const int INPUT2 = 50; 
const int INPUT3 = 51;
const int INPUT4 = 52;
const int ACCSDEVMODE = 57;
//-----------------------------------------------------
int User_Option;

class Login_class {
        public:
                string UserID, User, Password, Inputid, Registeredid, Pass;
                void Login();
};


void Login_class::Login()
{
	Clear_screen();
	ifstream input("AccountData.data");
	print("\n\n\n\t\t\tINPUT USERNAME AND PASSWORD ", color_black, color_blue);
	cout << endl;
	print("\t\t\t  USERNAME: ", color_light_blue);
	cin >> UserID;
        if (UserID == "back" || UserID == "exit") {
			LOGIN_DIALOGUE();
		}
	print("\t\t\t  ID: ", color_light_blue);
	cin >> Inputid;
        if (Inputid == "back" || Inputid == "exit") {
			LOGIN_DIALOGUE();;
		}
	print("\t\t\t  PASSWORD: ", color_light_blue);
	cin >> Password;
        if (Password == "back" || Password == "exit" ) {
			LOGIN_DIALOGUE();
		}
	while (input >> User >> Registeredid >> Pass)
	{
		if (User == UserID && Registeredid == Inputid && Pass == Password)
                {
		        CONFIRMSOUND();
	                Clear_screen();
                        print("\n\t\t\tWELCOME BACK " + UserID, color_black, color_green);
                        cout << "\n\t\t\t"; system("pause");
                        Menu();
		}
                else
	        {
                FAILSOUND();
		print("\n\t\t\tLOGIN ERROR\n", color_red); 
                cout << "\n\t\t\tplease check your username and password\n";
		cout << "\t\t\t"; system("pause");
                LOGIN_DIALOGUE();
	        }
                
	}
	input.close();
	
}



void LOGIN_DIALOGUE() 
{       
	Clear_screen();
        Login_class Login_form_class;
        Registration_Form Registration_Form_class;
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
                                        Login_form_class.Login();
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
                                        Registration_Form_class.Registration();
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
                                        Registration_Form_class.Forgot_Passwd();
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
void Menu()     
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
                                        Add_Student();
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


int main()      
{      
        Clear_screen();
        LOGIN_DIALOGUE();
        return 0;
        
}