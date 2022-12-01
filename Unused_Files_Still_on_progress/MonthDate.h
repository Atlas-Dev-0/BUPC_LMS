#include <bits/stdc++.h>
using namespace std;

string Month(int Numerical_form_of_month) 
{

    string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
    return Months[Numerical_form_of_month-1];
}