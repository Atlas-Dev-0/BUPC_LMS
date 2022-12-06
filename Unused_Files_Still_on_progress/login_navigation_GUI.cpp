#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "HeaderFiles/Console_Coloring_Header.h"
#include "HeaderFiles/Console_Integrated_Sounds.h"
using namespace std;



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


void hello() 
{
system("cls");
cout << "\t\t\t___________________________________________\n";
cout << "\t\t\t|WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM|\n";
cout << "\t\t\t|______________      Menu       __________|\n";
cout << "\t\t\t|                                         |" << endl;
cout << "\t\t\t|                                         |" << endl;
print(  "\t\t\t| [-] LOGIN                               |\n", color_black, color_cyan);
cout << "\t\t\t| [ ] REGISTER                            |" << endl;
cout << "\t\t\t| [ ] FORGOT PASSWORD                     |" << endl;
cout << "\t\t\t| [ ] EXIT                                |" << endl;
cout << "\t\t\t|_________________________________________|\n";
cout << endl;
}

void hell2() 
{
system("cls");
cout << "\t\t\t___________________________________________\n";
cout << "\t\t\t|WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM|\n";
cout << "\t\t\t|______________      Menu       __________|\n";
cout << "\t\t\t|                                         |" << endl;
cout << "\t\t\t|                                         |" << endl;
cout << "\t\t\t| [ ] LOGIN                               |" << endl;
print(  "\t\t\t| [-] REGISTER                            |\n", color_black, color_cyan);
cout << "\t\t\t| [ ] FORGOT PASSWORD                     |" << endl;
cout << "\t\t\t| [ ] EXIT                                |" << endl;
cout << "\t\t\t|_________________________________________|\n";
cout << endl;
}

void hell3() 
{
system("cls");
cout << "\t\t\t___________________________________________\n";
cout << "\t\t\t|WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM|\n";
cout << "\t\t\t|______________      Menu       __________|\n";
cout << "\t\t\t|                                         |" << endl;
cout << "\t\t\t|                                         |" << endl;
cout << "\t\t\t| [ ] LOGIN                               |" << endl;
cout << "\t\t\t| [ ] REGISTER                            |" << endl;
print(  "\t\t\t| [-] FORGOT PASSWORD                     |\n", color_black, color_cyan);
cout << "\t\t\t| [ ] EXIT                                |" << endl;
cout << "\t\t\t|_________________________________________|\n";
cout << endl;
}

void hell4() 
{
system("cls");
cout << "\t\t\t___________________________________________\n";
cout << "\t\t\t|WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM|\n";
cout << "\t\t\t|______________      Menu       __________|\n";
cout << "\t\t\t|                                         |" << endl;
cout << "\t\t\t|                                         |" << endl;
cout << "\t\t\t| [ ] LOGIN                               |" << endl;
cout << "\t\t\t| [ ] REGISTER                            |" << endl;
cout << "\t\t\t| [ ] FORGOT PASSWORD                     |" << endl;
print(  "\t\t\t| [-] EXIT                                |\n", color_black, color_cyan);
cout << "\t\t\t|_________________________________________|\n";
cout << endl;
}

void is_start_program(int x) {
    if ( x == 0) {
        hello();
    } else {
        cout << "";
    }
}



int reciever = 0;    
int main() {
while (true)
 {
    is_start_program(reciever);    
    int x;
    int KEYBOARD_LISTENER = _getch();
    // reciever is 0, it means default
    if (reciever == 0) { 
        hello();
        switch (KEYBOARD_LISTENER)
        {
        case KB_UP:
            hello();
            break;
        case KB_DOWN:
            hell2();
            reciever = 1;
            break;        
        default:
            break;
        }
    } else if (reciever == 1) {
        hell2();
        switch (KEYBOARD_LISTENER)
        {
            case KB_UP:
                hello();
                reciever = 0;
                break;
            case KB_DOWN:
                hell3();
                reciever = 2;
                break;
            
            default:
                break;
        } 
        
    } else if (reciever == 2) {
            hell3();
            switch (KEYBOARD_LISTENER)
            {
            case KB_UP:
                hell2();
                reciever = 1;
                break;
            case KB_DOWN:
                hell4();
                reciever = 3;
                break;
            
            default:
                break;
        } 

        }else if (reciever == 3) {
            hell4();
            switch (KEYBOARD_LISTENER)
            {
            case KB_UP:
                hell3();
                reciever = 2;
                break;
            case KB_DOWN:
                hello();
                reciever = 0;
                break;
            
            default:
                break;
    }
 }
 
 }
}