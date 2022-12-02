#include <bits/stdc++.h>
#include <windows.h>
#include "Book_Transaction.h"
#include "RegistrationForm.h"
#include "List_Students_Function.h"
using namespace std;

void LOGIN_DIALOUGE();
void Menu(); 

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

	ifstream input("AccountData.data");
	while (input >> User >> Registeredid >> Pass)
	{
		if (User == UserID && Registeredid == Inputid && Pass == Password)
		{       
			Is_Login_Successful();
			Clear_screen();
		}
                else
	        {
		cout << "\n\t\t\tLOGIN ERROR \n\t\t\tplease check your username and password\n";
		system("pause");
                Menu();
	        }
                
	}
	input.close();
	
}

void Login_class::Is_Login_Successful() 
{


        cout <<"\n\t\t\t"<< UserID << " Your LOGIN is successfull! \n";
        system("pause");
        Menu();
}

void Menu()     
{
        while (true)
        {
        Clear_screen();
        cout << "\t\t\t-----WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM-----\n";
        cout << "\t\t\t\t[1] Add a borrow Book\n";
        cout << "\t\t\t\t[2] List of Students\n"; 
        cout << "\t\t\t\t[3] List of Books\n"; 
        cout << "\t\t\t\t[4] Show Top Recommended Books\n"; 
        cout << "\t\t\t\t[5] EXIT\n"; 
        cin >> User_Option;

        switch (User_Option)
        {
        case 1:
                Add_Student();
                break;
        case 2:
                ListStudents();
                break;
        case 3:
        case 4:
        case 5:
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
        cout << "\t\t\t_________________________________________\n";
        cout << "\t\t\tWELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM\n";
        cout << "\t\t\t______________      Menu       __________\n\n\n";
        cout << "\t\t\t| 1 LOGIN                                |" << endl;
        cout << "\t\t\t| 2 REGISTER                             |" << endl;
        cout << "\t\t\t| 3 FORGOT PASSWORD                      |" << endl;
        cout << "\t\t\t| 4 EXIT                                 |" << endl;
        cout << "\n\t\t\t Please Enter your Choice: ";
        cin >> User_Option;
        cout << endl;

        switch (User_Option) {
        case 1: 
                Login_form_class.Login();
                break;
        case 2:
                Registration_Form_class.Registration();
                break;
        case 3: 
                Registration_Form_class.Forgot_Passwd();
                break;
        case 4:
                cout << "\t\t\tThank you! \n\n";
                break;
        case 128: 
                Beep(610,500);
                cout << "\n accessing developer mode \n";
                system("pause");
                Menu();
                break;
        default:
                cout << "\t\t\tPlease select from the options given above \n" << endl;
                Beep(610,500);
                LOGIN_DIALOUGE();
        }    
        }
}

int main()      
{       
        Clear_screen();
        LOGIN_DIALOUGE();
        return 0;
        
}