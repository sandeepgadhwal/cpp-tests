
#include <iostream>
// #include <cmath>

using namespace std;

struct student_info {
    int id;
    string name;
};

struct student_info_list {
    vector <student_info> rows;
};



int main() 
{
    cout << "Hello from Sandeep";
    cout << endl;

    student_info_list mylist;
    int counter = max(1, (int)mylist.rows.size());
    while (true){
        cout << "Please enter a student name or press enter to skip: ";
        string name;
        getline(cin, name);
        if (name == ""){
            break;
        }
        student_info row;
        row.id = counter++;
        row.name = name;
        mylist.rows.push_back(row);
    }

    for (student_info row: mylist.rows){
        cout << row.id << " " << row.name;
        cout << "\n";
    }

    cout << "\n";
    return 0;
}