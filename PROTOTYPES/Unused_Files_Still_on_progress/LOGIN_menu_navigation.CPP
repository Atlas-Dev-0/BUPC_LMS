#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "HeaderFiles/Book_Transaction.h"
#include "HeaderFiles/RegistrationForm.h"
#include "HeaderFiles/List_Students_Function.h"
#include "HeaderFiles/Console_Coloring_Header.h"
#include "HeaderFiles/Console_Integrated_Sounds.h"

//KEYBOARD LISTENER-------------------------------
const int KB_UP = 72; 
const int KB_DOWN = 80;
const int KB_RIGHT = 77;
const int KB_LEFT = 75;
const int ENT = 13;
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
                void Is_Login_Successful();
};


using namespace std;

void LOGIN_DIALOUGE_FIRST(); 
void LOGIN_DIALOUGE_SECOND();
void LOGIN_DIALOUGE_THIRD();
void LOGIN_DIALOUGE_ESC();


void Login_class::Login()
{
	Clear_screen();
	cout << "\t\t\t Please enter the usernane and password: " << endl;
	cout << "\t\t\t USERNAME: ";
	cin >> UserID;
	cout << "\t\t\t ID: ";
	cin >> Inputid;
	cout << "\t\t\t PASSWORD: ";
	cin >> Password;

	ifstream input("DATA/AccountData.data");
	while (input >> User >> Registeredid >> Pass)
	{
		if (User == UserID && Registeredid == Inputid && Pass == Password)
                {
		        GOODSOUND();
			Is_Login_Successful();
			Clear_screen();
		}
                else
	        {
                FAILSOUND();
		cout << "\n\t\t\tLOGIN ERROR \n\t\t\tplease check your username and password\n";
		cout << "\t\t\t"; system("pause");
                LOGIN_DIALOUGE_FIRST();
	        }
                
	}
	input.close();
	
}

void Login_class::Is_Login_Successful() 
{
        GOODSOUND();
        cout <<"\n\t\t\t"<< UserID << " Your LOGIN is successfull! \n";
        system("pause");
        LOGIN_DIALOUGE_FIRST();
}

void LOGIN_DIALOUGE_FIRST() 
{       

        Login_class LOGIN;
        while(true) {
                Clear_screen();
                
                cout << "\t\t\t___________________________________________\n";
                cout << "\t\t\t|WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM|\n";
                cout << "\t\t\t|______________      Menu       __________|\n";
                cout << "\t\t\t|                                         |" << endl;
                cout << "\t\t\t|                                         |" << endl;
                print(  "\t\t\t| [1] LOGIN                               |\n", color_black, color_cyan);
                cout << "\t\t\t| [2] REGISTER                            |" << endl;
                cout << "\t\t\t| [3] FORGOT PASSWORD                     | " << endl;
                cout << "\t\t\t| [ESC] EXIT                              |" << endl;
                cout << "\t\t\t|_________________________________________|\n";
                cout << endl;
                
               
                int arrowlisten = _getch();
                switch (arrowlisten) {
                case KB_UP:
                        LOGIN_DIALOUGE_ESC(); 
                        break;
                case KB_DOWN:
                        LOGIN_DIALOUGE_SECOND();
                        break;
                case ENT: 
                        CONFIRMSOUND();
                        LOGIN.Login();
                        
                case ACCSDEVMODE: 
                        CONFIRMSOUND();
                        print("\n\n\t\t\tAccessing developer mode \n", color_green);
                        cout << "\t\t\t"; system("pause");
                        break;
                default:
                        break;
                }    
        }
}
void LOGIN_DIALOUGE_SECOND() 
{       
        while(true) {
                Clear_screen();
                
                cout << "\t\t\t___________________________________________\n";
                cout << "\t\t\t|WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM|\n";
                cout << "\t\t\t|______________      Menu       __________|\n";
                cout << "\t\t\t|                                         |" << endl;
                cout << "\t\t\t|                                         |" << endl;
                cout << "\t\t\t| [1] LOGIN                               |" << endl;
                print(  "\t\t\t| [2] REGISTER                            |\n", color_black, color_cyan);
                cout << "\t\t\t| [3] FORGOT PASSWORD                     | " << endl;
                cout << "\t\t\t| [ESC] EXIT                              |" << endl;
                cout << "\t\t\t|_________________________________________|\n";
                cout << endl;
                
               
                int arrowlisten = _getch();
                switch (arrowlisten) {
                case KB_UP: 
                        LOGIN_DIALOUGE_FIRST();
                        break;
                case KB_DOWN:
                        LOGIN_DIALOUGE_THIRD();
                        break;
                case ACCSDEVMODE: 
                        CONFIRMSOUND();
                        print("\n\n\t\t\tAccessing developer mode \n", color_green);
                        cout << "\t\t\t"; system("pause");
                        break;
                default:
                        break;
                }    
        }
}
void LOGIN_DIALOUGE_THIRD() 
{       
        while(true) {
                Clear_screen();
                
                cout << "\t\t\t___________________________________________\n";
                cout << "\t\t\t|WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM|\n";
                cout << "\t\t\t|______________      Menu       __________|\n";
                cout << "\t\t\t|                                         |" << endl;
                cout << "\t\t\t|                                         |" << endl;
                cout << "\t\t\t| [1] LOGIN                               |" << endl;
                cout << "\t\t\t| [2] REGISTER                            |" << endl;
                print(  "\t\t\t| [3] FORGOT PASSWORD                     |\n", color_black, color_cyan);
                cout << "\t\t\t| [ESC] EXIT                              |" << endl;
                cout << "\t\t\t|_________________________________________|\n";
                cout << endl;
                
               
                int arrowlisten = _getch();
                switch (arrowlisten) {
                case KB_UP: 
                        LOGIN_DIALOUGE_SECOND();
                        break;
                case KB_DOWN:
                        LOGIN_DIALOUGE_ESC();
                        break;
                case ACCSDEVMODE: 
                        CONFIRMSOUND();
                        print("\n\n\t\t\tAccessing developer mode \n", color_green);
                        cout << "\t\t\t"; system("pause");
                        break;
                default:
                        break;
                }    
        }
}
void LOGIN_DIALOUGE_ESC() 
{       
        while(true) {
                Clear_screen();
                
                cout << "\t\t\t___________________________________________\n";
                cout << "\t\t\t|WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM|\n";
                cout << "\t\t\t|______________      Menu       __________|\n";
                cout << "\t\t\t|                                         |" << endl;
                cout << "\t\t\t|                                         |" << endl;
                cout << "\t\t\t| [1] LOGIN                               |" << endl;
                cout << "\t\t\t| [2] REGISTER                            |" << endl;
                cout << "\t\t\t| [3] FORGOT PASSWORD                     | " << endl;
                print(  "\t\t\t| [ESC] EXIT                              |\n", color_black, color_cyan);
                cout << "\t\t\t|_________________________________________|\n";
                cout << endl;
                
               
                int arrowlisten = _getch();
                switch (arrowlisten) {
                case KB_UP: 
                        LOGIN_DIALOUGE_THIRD();
                        arrowlisten = _getch();
                        break;
                case KB_DOWN:
                        LOGIN_DIALOUGE_FIRST();
                        break;
                case ENT:
                        exit(0);
                        break;
                case ACCSDEVMODE: 
                        CONFIRMSOUND();
                        print("\n\n\t\t\tAccessing developer mode \n", color_green);
                        cout << "\t\t\t"; system("pause");
                        break;
                default:
                        break;
                }    
        }
}


void LOGIN_menu_navigator() {
        LOGIN_DIALOUGE_FIRST();
}
