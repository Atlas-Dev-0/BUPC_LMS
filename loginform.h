#include <bits/stdc++.h>
#include <fstream>
#include "menu.h"
#include <windows.h>
using namespace std;

void login();
void registration();
void forgot();

int option;

void logindialogue() {
		//login dialouge 
        system("cls");
        cout << "\t\t\t_________________________________________\n";
        cout << "\t\t\tWELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM\n";
        cout << "\t\t\t______________      Menu       __________\n\n\n";
        cout << "\t\t\t| 1 LOGIN                                |" << endl;
        cout << "\t\t\t| 2 REGISTER                             |" << endl;
        cout << "\t\t\t| 3 FORGOT PASSWORD                      |" << endl;
        cout << "\t\t\t| 4 EXIT                                 |" << endl;
        cout << "\n\t\t\t Please Enter your Choice: ";
        cin >> option;
        cout << endl;


        switch (option) {
            case 1: 
                login();
                break;
            case 2:
                registration();
                break;
            case 3: 
                forgot();
                break;
            case 4:
                cout << "\t\t\tThank you! \n\n";
                break;
			case 128: 
				Beep(610,500);
				cout << "\n accessing developer mode \n";
				system("pause");
				menu();
				break;
            default:
                cout << "\t\t\tPlease select from the options given above \n" << endl;
                Beep(610,500);
				logindialogue();
        }    
}

void login()
{
	int count=0;
	string userID, user, password, inputid, registeredid, pass;
	system("cls");
	cout << "\t\t\t Please enter the usernane and password: " << endl;
	cout << "\t\t\t USERNAME: ";
	cin >> userID;
	cout << "\t\t\t ID: ";
	cin >> inputid;
	cout << "\t\t\t PASSWORD: ";
	cin >> password;

	ifstream input("AccountData.data");
	while (input >> user >> registeredid >> pass)
	{
		if (user == userID && registeredid == inputid && pass == password)
		{
			count = 1;
			system("cls");
		}
	}
	input.close();
	if (count == 1)
	{
		cout <<"\n\t\t\t"<<userID << " Your LOGIN is successfull! \n";
		system("pause");
		menu();
	}
	else
	{
		cout << "\n\t\t\tLOGIN ERROR \n\t\t\tplease check your username and password\n";
		system("pause");
	    logindialogue();
	}
}
void registration()
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
            logindialogue();
        } else if (rpass!=rpassword) {
            cout << "\t\t\tEnter the same password\n";
            system("pause");
            registration();
        } else {
            registration();
        }

	
}


void forgot()
{
	int option;
	system("cls");
	cout << "\t\t\t You forgot the password? No worries \n";
	cout << "\t\t\t| Press 1 to search your ID by username |" << endl;
	cout << "\t\t\t| Press 2 to go back to the main menu   |" << endl;
	cout << "\t\t\t Enter your choice: ";
	cin >> option;
	switch (option)
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
				//main();
			}
			else
			{
				cout << "\n\t\t\tSorry your account is not found! \n";
				//main();
			}
			break;
		}
		case 2:
		{
			//main();
		}
		default: 
			cout << "\t\t\t Wrong choice! Please try again " << endl;
			forgot();
	}

	
}



