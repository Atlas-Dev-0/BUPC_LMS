#pragma once
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <string> // for string data type

using namespace std;

// Function to generate a random ID composed of 5 characters
string generateRandomID()
{
    // Seed the random number generator with the current time
    srand(time(0));

    // Declare a string to store the random ID
    string id = "";

    // Generate a random character for each position in the ID
    for (int i = 0; i < 5; i++)
    {
        // Generate a random number between 0 and 25
        int randNum = rand() % 26;

        // Convert the number to a character and add it to the ID
        id += (char)(randNum + 'A');
    }

    // Return the generated ID
    return id;
}