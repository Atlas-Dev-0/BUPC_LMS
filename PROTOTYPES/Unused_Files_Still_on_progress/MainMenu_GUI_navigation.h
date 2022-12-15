#pragma once
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "Console_Coloring_Header.h"
#include "Console_Integrated_Sounds.h"
#include "Login_GUI_navigation.h"
using namespace std;

void MENU_DIALOGUE_FIRST(); 
void MENU_DIALOGUE_SECOND();
void MENU_DIALOGUE_THIRD();
void MENU_DIALOGUE_FOURTH();
void MENU_DIALOGUE_ESC();
void MENU_DIALOGUE_DEFAULT();

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


