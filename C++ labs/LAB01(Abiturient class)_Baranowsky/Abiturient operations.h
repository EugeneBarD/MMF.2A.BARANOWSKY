#ifndef abiturient_operations_h
#define abiturient_operations_h
#include <iostream>
#include <vector>

using namespace std;

vector<string> scoresText = { "Russian: ", "Mathematics: ", "Physics: " };
vector<string> subjectsText = { "Russian: ", "Belarussian: ", "English: ", "Mathematics: ", "Physics: ", "IT: ", "Biology: ", "Chemistry: ", "Geography: ", "History: " };
//FIXME Fix function for Centrilized testing and school middle mark

void DisplayScores(vector<int>);
void DisplaySubjects(vector<int>);

void DisplayScores(vector<int> scores)
{
    for (size_t i = 0; i < scores.size(); i++)
    {
        cout << "\t\t" << scoresText[i] << scores[i] << endl;
    }
}

void DisplaySubjects(vector<int> subjects)
{
    for (size_t i = 0; i < subjects.size(); i++)
    {
        cout << "\t\t" << subjectsText[i] << subjects[i] << endl;
    }
}

#endif