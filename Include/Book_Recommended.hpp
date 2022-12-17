#pragma once
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include "Console_Integrated_Sounds.h"
#include "Console_Coloring_Header.h"

using namespace std;

void Data_reset();

void Most_RecommendedBooks() {
    Clear_screen();
    // Create a vector of strings
    string database_line;
    ifstream Books_Used;
    Books_Used.open("Include/data/Book_used.data");
    vector<string> Used_Books;
    while (getline(Books_Used, database_line)) {
        string BookTitle;
        istringstream DataPull(database_line);
        DataPull >> BookTitle;
        Used_Books.push_back(BookTitle);
    }

    // Create a vector of pairs to store the strings and their counts
    vector<pair<string, int>> counts;

    // Loop through the vector of strings and increment the count for each string in the vector of pairs
    for (const string& s : Used_Books) {
        bool found = false;
        for (auto& [string, count] : counts) {
            if (string == s) {
                count++;
                found = true;
                break;
            }
        }
        if (!found) {
            counts.push_back({s, 1});
        }
    }
    
    // Sort the vector of pairs in descending order according to their counts
    sort(counts.begin(), counts.end(),[](const auto& a, const auto& b) { return a.second > b.second; });

    // Loop through the vector of pairs and print each string and its count
    print("\n\n-------------------------Most used books-------------------------\n\n", color_green);
    for (const auto& [string, count] : counts) {
        cout << "Points: " << count << "\t\tTitle: " << string << endl;
    }
    cout << endl;
}
    



