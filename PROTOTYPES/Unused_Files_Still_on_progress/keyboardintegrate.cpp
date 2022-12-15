#include <iostream>
#include <conio.h>
using namespace std;


//https://docstore.mik.ua/orelly/webprog/DHTML_javascript/0596004672_jvdhtmlckbk-app-b.html 



const int KB_UP = 72; 
const int num1 = 49; 
const int KB_DOWN = 80;
const int KB_RIGHT = 77;
const int KB_LEFT = 75;
const int ESC = 27;


void hello();
void hi();
int x;

void hello() {

    system("cls");
    x = 0;
    cout << "HELLO" << endl;
    int ch = _getch();
        ch = _getch();
        if (ch == num1) {
        hi();
        }
    }



void hi() 
    
    { 
        cout << "hi";
        
    }

int main() {
    x = 1;
    int hel;
    while (x == 1) {
        int ch = _getch();
        cin >> hel;
        if (ch == 224 || hel == 1) {
            ch = _getch();
            switch (ch) {
            case KB_UP: 
                hello();
                break;
            case KB_DOWN:
                std::cout << "down\n";
                break;
            case KB_RIGHT:
                std::cout << "right\n";
                break;
            case KB_LEFT:
                std::cout << "left\n";
                break;
            default: std::cout << "unknown\n";
            }
        }
        else if (ch == ESC)
        {
            std::cout << "Escape pressed, going out!\n";
            break;
        }
    }
}