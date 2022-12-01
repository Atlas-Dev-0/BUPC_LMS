#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>

using namespace std;

class Registration_Form 
{
	public:
		void Registration();
		void Forgot_Passwd();
		int User_Option;
};


void Registration_Form::Registration()
{
	string rusername, rpassword, ruserid, rpass;
	system("cls");
	cout << "\t\t\t Enter the username : ";
	cin >> rusername;
	cout << "\t\t\t Enter the authentication ID : ";
	cin >> ruserid;
	cout << "\t\t\t Enter the password : ";
	cin >> rpassword;
	cout << "\t\t\t Re-type the password : ";
	cin >> rpass;
        if (rpass == rpassword) {
            ofstream f1("AccountData.data", ios::app);
            f1 << rusername << ' ' << ruserid << ' ' << rpassword << endl;
            system("cls");
            cout << "\n\t\t\t Registration is successfull! \n";
            system("pause");
        } else if (rpass!=rpassword) {
            cout << "\t\t\tEnter the same password\n";
            system("pause");
            Registration();
        } else {
            Registration();
        }

	
}


void Registration_Form::Forgot_Passwd()
{
	int User_Option;
	system("cls");
	cout << "\t\t\t You Forgot_Passwd the password? No worries \n";
	cout << "\t\t\t| Press 1 to search your ID by username |" << endl;
	cout << "\t\t\t| Press 2 to go back to the main //Menu   |" << endl;
	cout << "\t\t\t Enter your choice: ";
	cin >> User_Option;
	switch (User_Option)
	{
		case 1: 
		{
			int count = 0;
			string registered_id, username, spass, sudo_id;
			cout << "\n\t\t\t Enter the authentication ID which you remembered: ";
			cin >> sudo_id;

			ifstream f2("AccountData.data");
			while (f2 >> username >> registered_id >> spass)
			{
				if (registered_id == sudo_id)
				{
					count = 1;
				}
			}
			f2.close();
			if (count == 1)
			{
				cout << "\n\t\t\tYour account is found! \n";
				cout << "\n\t\t\tYour password is: " << spass << endl;
				system("pause");
			}
			else
			{
				cout << "\n\t\t\tSorry your account is not found! \n";
				system("pause");
			}
			break;
		}
		case 2:
		{
			system("pause");
			break;
		}
		default: 
			cout << "\t\t\t Wrong choice! Please try again " << endl;
			Forgot_Passwd();
	}

	
}

