#ifndef abiturient_h
#define abiturient_h
#include <string>
#include <vector>

using namespace std;

class Abiturient 
{
public:

  Abiturient() {}
  Abiturient(string, string, string, string, vector<int>);
  ~Abiturient(){};

  void SetSurname(string);
  void SetName(string);
  void SetPatronymic(string);
  void SetAdress(string);
  void SetMarks(vector<int>);

  void SetAbiturient(string, string, string, string, vector<int>);

  string GetSurname();
  string GetName();
  string GetPatronymic();
  string GetAdress();
  vector<int> GetMarks();
  float GetMidMark();

  void EnterAbiturient();
  void DisplayAbiturient();

private:

  string surname = "", name = "", patronymic = "", adress = "";
  vector<int> marks;
  float midMark;
};

#endif