#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "Book_Transaction.h"
#include "Book_List.h"
using namespace std;


int Choice_Input;

void menu() {

    system("cls");
    cout << "\t\t\t-----WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM-----\n";
    cout << "\t\t\t\t[1] Add a borrow Book\n";
    cout << "\t\t\t\t[2] List of Students\n"; 
    cout << "\t\t\t\t[3] List of Books\n"; 
    cout << "\t\t\t\t[4] Show Top Recommended Books\n"; 
    cin >> Choice_Input;

    switch (Choice_Input)
    {

    case 1:
        Add_Student();
    case 2:
    case 3:
    case 4:
    default:
        break;
        
    }



}