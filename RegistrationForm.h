#pragma once
#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include "Console_Integrated_Sounds.h"
#include "Console_Coloring_Header.h"
#include "NAVIGATION_GUI.h"

using namespace std;

//KEYBOARD LISTENER-------------------------------
const int OPTION1 = 49; 
const int OPTION2 = 50; 
//------------------------------------------------

class Registration_Form 
{
	public:
		void Registration();
		void Forgot_Passwd();
		int User_Option;
};




void Registration_Form::Registration()
{
	string Input_from_user;
	vector<string> Input_Vector;
	for (int counter = 0; counter <= 4; counter++)
	{
		system("cls");
		print("\n\n\n\t\t\tREGISTRATION: PLEASE INPUT THE INFORMATION ASKED!", color_white, color_blue);
		cout << "\n\n";
		cout << "\t\t\t Enter the username : ";
		cin >> Input_from_user;
		if (Input_from_user == "exit") {
			break;
		}
		Input_Vector.push_back(Input_from_user);

		cout << "\t\t\t Enter the authentication ID : ";
		cin >> Input_from_user;
		if (Input_from_user == "exit") {
			break;
		}
		Input_Vector.push_back(Input_from_user);

		cout << "\t\t\t Enter the password : ";
		cin >> Input_from_user;
		if (Input_from_user == "exit") {
			break;
		}
		Input_Vector.push_back(Input_from_user);

		cout << "\t\t\t Re-type the password : ";
		cin >> Input_from_user;
		if (Input_from_user == "exit") {
			break;
		}
		Input_Vector.push_back(Input_from_user);

			if (Input_Vector[3] == Input_Vector[2]) {
				ofstream f1("AccountData.data", ios::app);
				f1 << Input_Vector[0] << ' ' << Input_Vector[1] << ' ' << Input_Vector[2] << endl;
				GOODSOUND();
				print("\n\t\t\t Registration is successful!!", color_black, color_green);
				cout << "\n\t\t\t"; system("pause");
				system("cls");
				break;
			} else if (Input_Vector[3]!=Input_Vector[2]) {
				FAILSOUND();
				print("\n\t\t\t Enter the SAME PASSWORD!!", color_black, color_red);
				cout << "\n\t\t\t"; system("pause");
				system("cls");
				break;
			} else {

			}
  }
}

void Registration_Form::Forgot_Passwd()
{
	system("cls");
	print("\n\n\n\t\t\tPASSWORD RECOVERY\n\n", color_black, color_blue);
	print("\t\t\t[1]", color_black, color_cyan); 
	cout << " ";
	print("SEARCH BY USERNAME\n", color_blue);
	print("\t\t\t[2]", color_black, color_cyan);
	cout << " ";
	print("GO BACK TO MAIN MENU\n", color_blue);
	
	print("\n\n\t\t\t Note:", color_black, color_blue);
    print(" Press the Key of your Choice!", color_black, color_cyan);

	int PRESSED_OPTION = _getch();
	switch (PRESSED_OPTION)
	{
		case OPTION1: 
		{
			int count = 0;
			CONFIRMSOUND();
			string registered_id, username, spass, sudo_id;
			system("cls");
			print("Enter the authentication ID which you remembered: ", color_blue);
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
				GOODSOUND();
				print("\n\n\n\t\t\tYour account is found! \n", color_black, color_blue);
				cout << "\n\t\t\tYour password is: " << spass << endl;
				cout << "\t\t\t"; system("pause");
			}
			else
			{
				FAILSOUND();
				print("\n\n\n\t\t\tSorry your account is not found! \n", color_white, color_red);
				cout << "\t\t\t"; system("pause");
			}
			break;
		}
		case OPTION2:
		{	
			break;
		}
		default: 
			Forgot_Passwd();
	}

}
