#ifndef abiturient_h
#define abiturient_h
#include <string>
#include <vector>

using namespace std;

class Abiturient
{
public:
	Abiturient() {};
	Abiturient(string, string, string, string, vector<int>, vector<int>);
	~Abiturient() {};

	void SetSurname(string);
	void SetName(string);
	void SetPatronymic(string);
	void SetAdress(string);
	void SetScores(vector<int>);
	void SetMarks(vector<int>);

	void SetAbiturient(string, string, string, string, vector<int>, vector<int>);

	string GetSurname();
	string GetName();
	string GetPatronymic();
	string GetAdress();
	vector<int> GetScores();
	vector<int> GetMarks();
	float GetMidMark();
	int GetResult();

	void EnterAbiturient();
	void DisplayAbiturient();

private:
	string surname = "", name = "", patronymic = "", adress = "";
	vector<int> scores;
	vector<int> marks;
	float midMark;
	int result;
};

#endif