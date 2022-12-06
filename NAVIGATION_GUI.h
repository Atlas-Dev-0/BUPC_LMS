#pragma once
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "Console_Coloring_Header.h"
#include "Console_Integrated_Sounds.h"
using namespace std;

//-------------------------------LOGIN MENU GUI's---------------------------------------
void LOGIN_DIALOGUE_FIRST(); 
void LOGIN_DIALOGUE_SECOND();
void LOGIN_DIALOGUE_THIRD();
void LOGIN_DIALOGUE_ESC();
void LOGIN_DIALOGUE_DEFAULT();
int LOGIN_GUI_RECIEVER = 0;    
void Check_if_program_firstRun(int reciever) {
        if ( reciever == 0) {
                LOGIN_DIALOGUE_FIRST();
        } else if ( reciever == 12 ) {
                LOGIN_DIALOGUE_DEFAULT();
                LOGIN_GUI_RECIEVER = 0;
        }
}

void LOGIN_DIALOGUE_DEFAULT() {
        
        system("cls");
        cout << "\t\t\t___________________________________________\n";
        cout << "\t\t\t|WELCOME TO BUPC LIBRARY MANAGEMENT SYSTEM|\n";
        cout << "\t\t\t|______________      Menu       __________|\n";
        cout << "\t\t\t|                                         |" << endl;
        cout << "\t\t\t|                                         |" << endl;
        cout << "\t\t\t| [ ] LOGIN                               |" << endl;
        cout << "\t\t\t| [ ] REGISTER                            |" << endl;
        cout << "\t\t\t| [ ] FORGOT PASSWORD                     |" << endl;
        cout << "\t\t\t| [ ] EXIT                                |" << endl;
        cout << "\t\t\t|_________________________________________|\n";
        cout << endl;


}
void LOGIN_DIALOGUE_FIRST() {

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
void LOGIN_DIALOGUE_SECOND() {

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
void LOGIN_DIALOGUE_THIRD() {
        
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
void LOGIN_DIALOGUE_EXIT() {

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

//-------------------------------MAIN MENU GUI's---------------------------------------
void MENU_DIALOGUE_FIRST(); 
void MENU_DIALOGUE_SECOND();
void MENU_DIALOGUE_THIRD();
void MENU_DIALOGUE_FOURTH();
void MENU_DIALOGUE_ESC();
void MENU_DIALOGUE_DEFAULT();
int MENU_GUI_RECIEVER = 0;    
void Check_if_program_firstRun_menu(int reciever) {
        if ( reciever == 0) {
                MENU_DIALOGUE_FIRST();
        } else if ( reciever == 12 ) {
                MENU_DIALOGUE_DEFAULT();
                MENU_GUI_RECIEVER = 0;
        }
}

void MENU_DIALOGUE_DEFAULT() {
        
        system("cls");
        print("\t\t\t                  WELCOME TO BUPC LIBRARY          .", color_white, color_orange);
        cout << endl;
        cout << "\t\t\t____________________________________________________\n";
        cout << "\t\t\t|                                                  |\n";
        cout << "\t\t\t|  [ ] Add a borrow Book                           |\n";
        cout << "\t\t\t|  [ ] List of Students                            |\n"; 
        cout << "\t\t\t|  [ ] List of Books                               |\n"; 
        cout << "\t\t\t|  [ ] Show Top Recommended Books                  |\n"; 
        cout << "\t\t\t|  [ ] EXIT                                        |\n"; 
        cout << "\t\t\t|__________________________________________________|";


}
void MENU_DIALOGUE_FIRST() {

        system("cls");
        print("\t\t\t                  WELCOME TO BUPC LIBRARY          .", color_white, color_orange);
        cout << endl;
        cout << "\t\t\t____________________________________________________\n";
        cout << "\t\t\t|                                                  |\n";
        print(  "\t\t\t|  [*] Add a borrow Book                           |\n", color_white, color_blue);
        print(  "\t\t\t|  [ ] List of Students                            |\n");
        print(  "\t\t\t|  [ ] List of Books                               |\n");
        print(  "\t\t\t|  [ ] Show Top Recommended Books                  |\n");
        print(  "\t\t\t|  [ ] EXIT                                        |\n");
        cout << "\t\t\t|__________________________________________________|";

}
void MENU_DIALOGUE_SECOND() {

        system("cls");  
        print("\t\t\t                  WELCOME TO BUPC LIBRARY          .", color_white, color_orange);
        cout << endl;
        cout << "\t\t\t____________________________________________________\n";
        cout << "\t\t\t|                                                  |\n";
        print(  "\t\t\t|  [ ] Add a borrow Book                           |\n");
        print(  "\t\t\t|  [*] List of Students                            |\n", color_white, color_blue);
        print(  "\t\t\t|  [ ] List of Books                               |\n");
        print(  "\t\t\t|  [ ] Show Top Recommended Books                  |\n");
        print(  "\t\t\t|  [ ] EXIT                                        |\n");
        cout << "\t\t\t|__________________________________________________|";
        

}
void MENU_DIALOGUE_THIRD() {
        
        system("cls");
        print("\t\t\t                  WELCOME TO BUPC LIBRARY          .", color_white, color_orange);
        cout << endl;
        cout << "\t\t\t____________________________________________________\n";
        cout << "\t\t\t|                                                  |\n";
        print(  "\t\t\t|  [ ] Add a borrow Book                           |\n");
        print(  "\t\t\t|  [ ] List of Students                            |\n");
        print(  "\t\t\t|  [*] List of Books                               |\n", color_white, color_blue);
        print(  "\t\t\t|  [ ] Show Top Recommended Books                  |\n");
        print(  "\t\t\t|  [ ] EXIT                                        |\n");
        cout << "\t\t\t|__________________________________________________|";
}
void MENU_DIALOGUE_FOURTH() {
        
        system("cls");
        print("\t\t\t                  WELCOME TO BUPC LIBRARY          .", color_white, color_orange);
        cout << endl;
        cout << "\t\t\t____________________________________________________\n";
        cout << "\t\t\t|                                                  |\n";
        print(  "\t\t\t|  [ ] Add a borrow Book                           |\n");
        print(  "\t\t\t|  [ ] List of Students                            |\n");
        print(  "\t\t\t|  [ ] List of Books                               |\n");
        print(  "\t\t\t|  [*] Show Top Recommended Books                  |\n", color_white, color_blue);
        print(  "\t\t\t|  [ ] EXIT                                        |\n");
        cout << "\t\t\t|__________________________________________________|";
}

void MENU_DIALOGUE_EXIT() {

        system("cls");
        print("\t\t\t                  WELCOME TO BUPC LIBRARY          .", color_white, color_orange);
        cout << endl;
        cout << "\t\t\t____________________________________________________\n";
        cout << "\t\t\t|                                                  |\n";
        print(  "\t\t\t|  [ ] Add a borrow Book                           |\n");
        print(  "\t\t\t|  [ ] List of Students                            |\n");
        print(  "\t\t\t|  [ ] List of Books                               |\n");
        print(  "\t\t\t|  [ ] Show Top Recommended Books                  |\n");
        print(  "\t\t\t|  [*] EXIT                                        |\n", color_white, color_blue);
        cout << "\t\t\t|__________________________________________________|";
 }