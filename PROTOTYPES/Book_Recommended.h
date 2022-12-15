#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "Console_Integrated_Sounds.h"
#include "Console_Coloring_Header.h"
#include "MainMenu_and_BookTransaction.h"

using namespace std;


class Book
{
    public:
        string title;
        int usageCount;
        Book (string &title, int &usageCount) {
            this->title=title;
            this->usageCount=usageCount;
        }
};
void Data_reset();

void Most_RecommendedBooks() {
    system("cls");
    // Create a vector of strings
    vector<string> vec;

    string cvariable;
    ifstream reading_variable("Book_used.data");
    string reading_line;

    if(!reading_variable.is_open()) std::cout << "Error: File, Open" << endl;

    while (reading_variable.good()){
        getline(reading_variable,reading_line);
        vec.push_back(reading_line);
    }

    // Create an unordered map to store the counts of each string
    unordered_map<string, int> counts;

    // Loop through the vector and count the number of times each string occurs
    for (const string& str : vec) {
        counts[str]++;
    }

    ofstream creating_variable("Recommended_Books_with_usage.data", ios::app);
    // Output the counts for each string
    for (const auto& [str, count] : counts) {
        creating_variable << str  << " " << count << endl ;
    }
    
    vector<Book> books;  // vector to store the list of books and their usage counts

    ifstream Sorting_Variable("Recommended_Books_with_usage.data");
    string Sorting_Variable_read_line;

    if(!Sorting_Variable.is_open()) std::cout << "Error: File, Open" << endl;

    while (getline(Sorting_Variable,Sorting_Variable_read_line)){
        string Name;
        int Usage;
        istringstream Data_Pull(Sorting_Variable_read_line);
        if (Sorting_Variable.empty()) {
            
        }
        Data_Pull >> Name >> Usage;
        Book Data(Name, Usage);
        books.push_back(Data);
    }

    sort(books.begin(), books.end(), [](Book a, Book b) {return a.usageCount > b.usageCount;});
        
    // Print the sorted books and their usage counts
    cout << endl << "-------------------------Most used books-------------------------" << endl;
    for (int i = 0; i < books.size()-1; i++)
    {
        cout << books[i].title << " |  Points: " << books[i].usageCount << endl;
    }

    int option;
    cout << "[1] Go back\t\t[2] Reset Database" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        //breaks function
        break;
    case 2:
        Data_reset();
        break;
    default:
        break;
    }

    system("pause");
    ofstream DELETION;
    DELETION.open("Recommended_Books_with_usage.data", ofstream::out | ofstream::trunc);
    DELETION.close();
}
    
void Data_reset() 
{
    string option;
    cout << "Reset DataBase? (Y/N)" << endl;
    cin >> option;

    if (option == "Y" || option == "y") {
        ofstream DELETION;
        DELETION.open("Book_used.data", ofstream::out | ofstream::trunc);
        DELETION.close();
    } else if (option == "N" || option == "n"){
        Most_RecommendedBooks();
    } else {
        cout << "NO OPTION, TRY AGAIN" << endl;
        Data_reset();
    }

}


