#include "Abiturient.h"
#include <string.h>

Abiturient::Abiturient(string, string, string, string, vector<int>){

};

void Abiturient::SetSurname(string surname) { this->surname = surname; };

void Abiturient::SetName(string name) { this->name = name; };

void Abiturient::SetPatronymic(string patronymic) { this->patronymic = patronymic; };

void Abiturient::SetAdress(string adress) { this->adress = adress; };

void Abiturient::SetMarks(vector<int> marks) { this->marks = marks; };

void Abiturient::SetAbiturient(string surname, string name, string patronymic, string adress, vector<int> marks) 
{
  SetSurname(surname);
  SetName(name);
  SetPatronymic(patronymic);
  SetAdress(adress);
  SetMarks(marks);

  int sum = 0;
  for (int i = 0; i < marks.size(); i++) 
  {
    sum += marks[i];
  }
  this->midMark = (float)sum / marks.size();
};

string Abiturient::GetSurname()
{

};

string Abiturient::GetName()
{

};

string Abiturient::GetPatronymic()
{

};

string Abiturient::GetAdress()
{

};

vector<int> Abiturient::GetMarks()
{

};

float Abiturient::GetMidMark()
{

};

void Abiturient::EnterAbiturient()
{

};

void Abiturient::DisplayAbiturient()
{

};
