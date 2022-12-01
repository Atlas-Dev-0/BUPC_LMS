// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Comparator Function
bool myCmp(string s1, string s2)
{
 
    // If size of numeric strings
    // are same the put lowest value
    // first
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
 
    // If size is not same put the
    // numeric string with less
    // number of digits first
    else {
        return s1.size() < s2.size();
    }
}
 
// Driver Code
int main()
{
    vector<string> v;
    int number_of_lines = 0;
    string output, line, firstname, lastname;
    ifstream myfile("prototypedatabase.data");
    if(myfile.is_open()) {  
        while(!myfile.eof()){
            myfile >> firstname >> lastname;
            output = firstname; 
            v.push_back(output);
            number_of_lines++;
        }
        myfile.close();
    } else {
        cout << "\nDATABASE EMPTY\n";
        system("pause");
    }
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    cout << "--------------------------\n";
    // Calling sort function with
    // custom comparator


    sort(v.begin(), v.end(), myCmp);
 
    // Print the vector values after
    // sorting
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }


 
}