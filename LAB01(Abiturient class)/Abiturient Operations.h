#ifndef abiturient_operations_h
#define abiturient_operations_h
#include <iostream>
#include <vector>

using namespace std;

vector<string> subjects = {"Russian: ", "Mathematics: ", "Physics: ", "IT: ", "English: "};

void DisplayMarks(vector<int>);

void DisplayMarks(vector<int> marks)
{
    for (int i = 0; i < marks.size(); i++) 
    {
        cout << subjects[i] << marks[i];
    }
}

#endif