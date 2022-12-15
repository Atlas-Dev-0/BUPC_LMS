#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
using namespace std;


int main() 
{
    time_t now = time(0);
    tm* Local_time = localtime(&now);

    // print various components of tm structure.
    int month = Local_time->tm_mon;
    int day = Local_time->tm_mday;
    cout << day + 7 << ", " << month << endl;
    cout << "Month: "<< 1 + Local_time->tm_mon<< endl;
    cout << "Day: "<< Local_time->tm_mday << endl;
    
}