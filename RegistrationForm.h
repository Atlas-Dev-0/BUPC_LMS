#pragma once
#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include "Console_Integrated_Sounds.h"
#include "Console_Coloring_Header.h"
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
	string Input_from_user;
	vector<string> Input_Vector;
	for (int counter = 0; counter <= 4; counter++)
	{
		system("cls");
		print("\t\t\t HELLO USER! PLEASE INPUT THE INFORMATION ASKED!", color_black, color_blue);
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
				break;
			} else if (Input_Vector[3]!=Input_Vector[2]) {
				FAILSOUND();
				print("\n\t\t\t Enter the SAME PASSWORD!!", color_black, color_red);
				cout << "\n\t\t\t"; system("pause");
				break;
			} else {

			}
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
