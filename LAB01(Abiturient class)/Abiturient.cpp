#include "Abiturient.h"
#include "Abiturient Operations.h"
#include <iostream>
#include <string.h>

using namespace std;

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
  string surname, name, patronymic, adress;
  vector<int> marks;
  int mark = 0;
  
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

  cout << "Enter marks: \n";
  for (int i = 0; i < subjects.size(); i++) 
  {
    cout << "\t" << subjects[i];
    cin >> mark;
    marks.push_back(mark);
  }
  this->SetAbiturient(surname, name, patronymic, adress, marks);
};

void Abiturient::DisplayAbiturient() {
  cout << endl
       << "--------------------------------------------------------------------"
          "-------------------------------";
  cout << "\nPersonal Archive:" << endl;
  cout << "\nFirstName: " << this->name << ".";
  cout << "\tLastName: " << this->surname << ".";
  cout << "\tPatronymic: " << this->patronymic << ".";
  cout << "\n\nAdress: " << this->adress << ".";
  DisplayMarks(this->marks);
  cout << "\nMiddle mark: " << this->midMark << "." << endl;
  cout << endl
       << "--------------------------------------------------------------------"
          "-------------------------------"
       << endl;
};
