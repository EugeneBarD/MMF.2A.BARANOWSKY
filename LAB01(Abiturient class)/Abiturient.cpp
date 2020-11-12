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

string Abiturient::GetSurname() { return this->surname; };

string Abiturient::GetName() { return this->name; };

string Abiturient::GetPatronymic() { return this->patronymic; };

string Abiturient::GetAdress() { return this->adress; };

vector<int> Abiturient::GetMarks() { return this->marks; };

float Abiturient::GetMidMark() { return this->midMark; };

void Abiturient::EnterAbiturient()
{

};

void Abiturient::DisplayAbiturient()
{

};
