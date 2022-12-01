#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class EmployeeInformation {
public:
    string firstName;
    string lastName;
    string title;
    string phonenumber;

EmployeeInformation(string &firstName,string &lastName,string &title,string &phonenumber)
{
this->firstName = firstName;
this->lastName = lastName;
this->title = title;            //there is no variable named initial in class
this->phonenumber = phonenumber; //there is no variable named id in class
}
};

int main()
{
    ifstream file;

    file.open("prototypedatabase.data");
    if (!file.is_open())
    {
        cout << "Error opening file";
        return 0;
    }

    vector<EmployeeInformation> employees;
    string line;

    while (getline(file, line))
    {
        string firstName, lastName, title, phonenumber;
        istringstream iss(line);
        iss >> firstName >> lastName >> title >> phonenumber;
        EmployeeInformation person(firstName, lastName, title, phonenumber);
        employees.push_back(person);
    }

    sort(employees.begin(), employees.end(), [](EmployeeInformation a, EmployeeInformation b) { return a.lastName < b.lastName; });  //there should be a semicolon after return statement

    for (EmployeeInformation i : employees)
    {
        // print person info in sorted order
        cout << i.lastName << ", " << i.firstName << " " << i.title << " " << i.phonenumber << endl;
    }

    return 0;
}