#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;



vector<string> databaseline;
int number_of_lines = 0;
int choice;

void menu(); 
void getline(); 
void sortbylastname();


int main() {
    string firstname;
    string lastname;
    system("cls");
    ofstream database("prototypedatabase.data", ios::app);
    cout << "Add firstname: ";
    cin >> firstname;
    cout << "Add lastname: ";
    cin >> lastname;

    database << firstname << " " << lastname << endl;
    database.close();
    getline(); //going to the size
    

}

void getline() {
    //getline

    string firstname, lastname, line, output;
    ifstream database("prototypedatabase.data", ios::app);
    if (database.is_open()) {
        while(!database.eof()) {
            getline(database, line);
            database >> firstname >> lastname;
            output = "Name: " + firstname + " " + lastname;
            databaseline.push_back(output);
            number_of_lines++; //getting size of vector database
        }
        database.close();
    } else {
        cout << "\n DATABASE EMPTY \n";

    }
    menu();
}

void menu() {

    
    if (databaseline.size() <= 0 && number_of_lines == 0) {
        getline();
    } else { 
        cout << "-----------LIST-----------\n";
        
        for (int i = 0; i < number_of_lines-1; i++) {

            cout << databaseline.at(i) << endl; 
            cout << "\n";

        }

        cout << "[1] SORT BY LASTNAME" << endl;
        cout << "Sort by: "; cin >> choice;
        switch (choice)
        {
        case 1:
            sortbylastname();
            break;
        
        default:
            break;
        }
    }
}


void sortbylastname() {
    
}

