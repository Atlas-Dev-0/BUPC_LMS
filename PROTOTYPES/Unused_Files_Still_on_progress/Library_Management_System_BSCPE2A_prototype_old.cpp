#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "HeaderFiles/Book_Transaction.h"
#include "HeaderFiles/RegistrationForm.h"
#include "HeaderFiles/List_Students_Function.h"
#include "HeaderFiles/Console_Coloring_Header.h"
#include "HeaderFiles/Console_Integrated_Sounds.h"
using namespace std;

void LOGIN_DIALOUGE();
void Menu(); 


//KEYBOARD LISTENER------------------------------
const int INPUT1 = 49; 
const int INPUT2 = 50; 
const int INPUT3 = 51;
const int INPUT4 = 52;
const int ACCSDEVMODE = 57;
const int ESC = 27;
//-----------------------------------------------

int User_Option;

class Login_class {
        public:
                string UserID, User, Password, Inputid, Registeredid, Pass;
                void Login();
                void Is_Login_Successful();
};


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
                LOGIN_DIALOUGE();
	        }
                
	}
	input.close();
	
}

void Login_class::Is_Login_Successful() 
{
        GOODSOUND();
        cout <<"\n\t\t\t"<< UserID << " Your LOGIN is successfull! \n";
        system("pause");
        Menu();
}

void Menu()     
{
        while (true)
        {
                Clear_screen();
                print("\t\t\t                  WELCOME TO BUPC LIBRARY          .", color_white, color_orange);
                cout << endl;
                cout << "\t\t\t____________________________________________________\n";
                cout << "\t\t\t|                                                  |\n";
                cout << "\t\t\t|  [1] Add a borrow Book                           |\n";
                cout << "\t\t\t|  [2] List of Students                            |\n"; 
                cout << "\t\t\t|  [3] List of Books                               |\n"; 
                cout << "\t\t\t|  [4] Show Top Recommended Books                  |\n"; 
                cout << "\t\t\t|  [ESC] EXIT                                      |\n"; 
                cout << "\t\t\t|__________________________________________________|";
                
                print("\n\n\t\t\t Note:", color_black, color_blue);
                print(" Press the Key of your Choice!", color_black, color_cyan);
                
                int Input_from_Keyboard = _getch();
                switch (Input_from_Keyboard)
                
                {
                        case INPUT1:
                                CONFIRMSOUND();
                                Add_Student();
                                break;
                        case INPUT2:
                                CONFIRMSOUND();
                                ListStudents();
                                break;

                        case INPUT3:

                        case INPUT4:
                        
                        case ESC:
                                exit(0);
                                break;
                        default:
                                break;
                
        }
    }
}

void LOGIN_DIALOUGE() 
{       
        Login_class Login_form_class;
        Registration_Form Registration_Form_class;
        
        
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
                cout << "\t\t\t| [ESC] EXIT                              |" << endl;
                cout << "\t\t\t|_________________________________________|\n";
                cout << endl;
                print("\n\t\t\t Note:", color_black, color_blue);
                print(" Press the Key of your Choice!", color_black, color_cyan);
                int Input_from_Keyboard = _getch();
                switch (Input_from_Keyboard) {
                case INPUT1: 
                        CONFIRMSOUND();
                        Login_form_class.Login();
                        break;
                case INPUT2:
                        CONFIRMSOUND();
                        Registration_Form_class.Registration();
                        break;
                case INPUT3: 
                        CONFIRMSOUND();
                        Registration_Form_class.Forgot_Passwd();
                        break;
                case ESC:
                        Beep(500,600);
                        Beep(400,500);
                        Clear_screen();
                        print("SHUTTING DOWN", color_white, color_red);
                        cout << "\n"; system("PAUSE");
                        exit(0);
                        break;
                case ACCSDEVMODE: 
                        CONFIRMSOUND();
                        print("\n\n\t\t\tAccessing developer mode \n", color_green);
                        cout << "\t\t\t"; system("pause");
                        Menu();
                        break;
                default:
                        LOGIN_DIALOUGE();
                        break;
                }    
        }
}

int main()      
{      
        Clear_screen();
        LOGIN_DIALOUGE();
        return 0;
        
}