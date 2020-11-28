#include <iostream>
#include <string.h>
#include <vector>
#include "Abiturient.h"
#include "Abiturient operations.h"

using namespace std;

Abiturient::Abiturient(string surname, string name, string patronymic, string adress, vector<int> scores, vector<int> marks)
{
    SetAbiturient(surname, name, patronymic, adress, scores, marks);
};

void Abiturient::SetSurname(string surname) { this->surname = surname; };

void Abiturient::SetName(string name) { this->name = name; };

void Abiturient::SetPatronymic(string patronymic) { this->patronymic = patronymic; };

void Abiturient::SetAdress(string adress) { this->adress = adress; };

void Abiturient::SetScores(vector<int> scores) { this->scores = scores; };

void Abiturient::SetMarks(vector<int> marks) { this->marks = marks; };

void Abiturient::SetAbiturient(string surname, string name, string patronymic, string adress, vector<int> scores, vector<int> marks)
{
    SetSurname(surname);
    SetName(name);
    SetPatronymic(patronymic);
    SetAdress(adress);
    SetScores(scores);
    SetMarks(marks);

    int markSum = 0;
    for (size_t i = 0; i < marks.size(); i++)
    {
        markSum += marks[i];
    }
    this->midMark = round(((float)markSum / marks.size())*10)/10;

    int scoreSum = 0;  
    for (size_t i = 0; i < scores.size(); i++)
    {
        scoreSum += scores[i];
    }

    this->result = round(((float)markSum / marks.size()) * 10) + scoreSum;
};

string Abiturient::GetSurname() { return this->surname; };

string Abiturient::GetName() { return this->name; };

string Abiturient::GetPatronymic() { return this->patronymic; };

string Abiturient::GetAdress() { return this->adress; };

vector<int> Abiturient::GetScores() { return this->scores; };

vector<int> Abiturient::GetMarks() { return this->marks; };

float Abiturient::GetMidMark() { return this->midMark; };

int Abiturient::GetResult() { return this->result; };

void Abiturient::EnterAbiturient()
{
    string surname, name, patronymic, adress;
    vector<int> scores;
    vector<int>marks;
    int num = 0;

    cout << "Enter surname of student:";
    cin.ignore();
    cin >> surname;
    cout << "Enter name of student:";
    cin >> name;
    cout << "Enter patronymic:";
    cin >> patronymic;

    cout << "Enter adress:";
    cin.ignore();
    cin >> adress;

    cout << "Enter scores: \n";
    for (size_t i = 0; i < scoresText.size(); i++)
    {
        cout << "\t" << scoresText[i];
        cin >> num;
        scores.push_back(num);
    }

    cout << "Enter marks: \n";
    for (size_t i = 0; i < subjectsText.size(); i++)
    {
        cout << "\t" << subjectsText[i];
        cin >> num;
        marks.push_back(num);
    }
    this->SetAbiturient(surname, name, patronymic, adress, scores, marks);
};

void Abiturient::DisplayAbiturient()
{
    cout << endl
        << "--------------------------------------------------------------------"
        "-------------------------------";
    cout << "\nPersonal Archive:" << endl;
    cout << "\nFirstName: " << this->name << ".";
    cout << "\tLastName: " << this->surname << ".";
    cout << "\tPatronymic: " << this->patronymic << ".";
    cout << "\n\nAdress: " << this->adress << ".";
    cout << "\n\tScores:" << "\n";
    DisplayScores(this->scores);
    cout << "\n\tMarks:" << "\n";
    DisplaySubjects(this->marks);
    cout << "\nMiddle mark: " << this->midMark << ".";
    cout << "\nResultative score: " << this->result << ".";
    cout << endl
        << "--------------------------------------------------------------------"
        "-------------------------------"
        << endl;
};