#include<bits/stdc++.h>
#include<vector>
using namespace std;


int number_of_lines = 0;

struct date {
int firstname;
int secondname;
};


int main() {
    
    struct date input[number_of_lines];
    vector<int> v;
    int output, line, fname, lname;
    ifstream myfile("prototypedatabase.data");
    if(myfile.is_open()) {  
        while(!myfile.eof()){
            number_of_lines++;
            myfile >> fname >> lname;
            input[number_of_lines].firstname = fname;
            input[number_of_lines].secondname = lname;
        }
        myfile.close();
    } else {
        cout << "\nDATABASE EMPTY\n";
        system("pause");
    }
    
    
    for(int i=0; i<number_of_lines; i++) {
        input[i].firstname;
        
        
    }

    for(int i = 0; i < number_of_lines-1; i++) {
            for (int j=i+1; j < number_of_lines; j++) {
                if (input[i].secondname > input[j].secondname) {
                    struct date temp = input[i];
                    input[i] = input[j];
                    input[j] = temp;
                } else if (input[i].secondname == input[j].secondname && input[i].firstname > input[j].firstname) {
                    struct date temp = input[i];
                    input[i] = input[j];
                    input[j] = temp;
                }
        }
    }
       
    cout << "\n------SORTED SCHEDUES------" << endl;

    for(int i = 0; i<number_of_lines; i++) {
        cout<< "firstname:" <<input[i].firstname<< ", secondname:" <<
        input[i].secondname << endl;
    }
}
