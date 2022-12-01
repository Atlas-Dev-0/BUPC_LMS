#include <bits/stdc++.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
using namespace std;

class BorrowedBook_Information {
    public: 
        string Student_firstname;
        string Student_lastname;
        string Student_id;
        string Yearlevel;
        string Book_Category;
        string Book_Author;

        BorrowedBook_Information(string &Student_firstname, string &Student_lastname, string &Student_id, string &Yearlevel, string &Book_Category, string &Book_Author) 
        {
            this->Student_firstname = Student_firstname;
            this->Student_lastname = Student_lastname;
            this->Student_id = Student_id;
            this->Yearlevel = Yearlevel;
            this->Book_Category = Book_Category;
            this->Book_Author = Book_Author;

        }        
};

    
int main(int argc, char**argv) {

    ifstream database;

    database.open("borrowedbooks.data");
    if (!database.is_open()) 
    {
        cout << "Database Not Found";
        return 0;
    }

    vector<BorrowedBook_Information> BorrowedBook_Database;
    string database_line;

    while (getline(database, database_line)) 
    {
        string  Student_firstname,
                Student_lastname,
                Student_id,
                Yearlevel,
                Book_Category,
                Book_Author;

        istringstream stream(database_line);
        stream >> Student_firstname >> Student_lastname >> Student_id >> Yearlevel >> Book_Category >> Book_Author;
        BorrowedBook_Information Student_with_Book(Student_firstname, Student_lastname, Student_id, Yearlevel, Book_Category, Book_Author);
        BorrowedBook_Database.push_back(Student_with_Book);

    }

    //Sorting Method
    sort(BorrowedBook_Database.begin(), BorrowedBook_Database.end(), [](BorrowedBook_Information a, BorrowedBook_Information b) {return a.Student_lastname < b.Student_lastname;});
    int Student_Count = 1;
    for (BorrowedBook_Information i : BorrowedBook_Database) 
    {
        
        cout << Student_Count++ << " STUDENT: " << i.Student_lastname << ", " << i.Student_firstname << endl;
    }

}