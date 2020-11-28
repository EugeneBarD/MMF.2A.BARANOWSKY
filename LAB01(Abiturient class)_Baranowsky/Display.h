#ifndef display_h
#define display_h
#include <iostream>

using namespace std;

void DisplayMenu(vector<Abiturient>&);
int DisplayText();
void Display(vector<Abiturient>&);
void DisplayBad(vector<Abiturient>&);
void DisplayWithOverSum(vector<Abiturient>&);
void DisplayHighest(vector<Abiturient>&);
void DisplayPassed(vector<Abiturient>&);
void SystemFan();
void AbiturientSwap(Abiturient&, Abiturient&);

void DisplayMenu(vector<Abiturient>& group)
{
	enum
	{
		Display_c = 1,
		DisplayBad_c,
		DisplayWithOverSum_c,
		DisplayHighest_c,
		DisplayPassed_c,
		Exit
	};

	while (true)
	{
		int key = DisplayText();
		if (key == Exit)
			return;
		switch (key)
		{
		case Display_c:
			Display(group);
			SystemFan();
			break;
		case DisplayBad_c:
			DisplayBad(group);
			SystemFan();
			break;
		case DisplayWithOverSum_c:
			DisplayWithOverSum(group);
			SystemFan();
			break;
		case DisplayHighest_c:
			DisplayHighest(group);
			SystemFan();
			break;
		case DisplayPassed_c:
			DisplayPassed(group);
			SystemFan();
			break;
		default:
			cout << "Invalid input! Enter number 1...6";
			break;
		}
	}
}

int DisplayText()
{
	int key;
	cout << "\nEnter the number of operation:"
		"\n>> 1 - Display all abiturients"
		"\n>> 2 - Display abiturients that have a bad marks"
		"\n>> 3 - Display abiturients that have a sum of scores over 'N'"
		"\n>> 4 - Display 'N' abiturients that have the highest sum of scores"
		"\n>> 5 - Display abiturients that have semi-pass score"
		"\n>> 6 - Exit\n>> ";
	cin >> key;
	system("pause");
	system("cls");
	return key;
}

void Display(vector<Abiturient>& group)
{
	for (size_t i = 0; i < group.size(); i++)
	{
		group[i].DisplayAbiturient();
	}
}

void DisplayBad(vector<Abiturient>& group)
{
	vector<Abiturient> badGroup;
	for (size_t i = 0; i < group.size(); i++)
	{
		vector<int> buffMarks = group[i].GetMarks();
		for (size_t j = 0; j < buffMarks.size(); j++)
		{
			if (buffMarks[j] <= 5)
			{
				badGroup.push_back(group[i]);
				break;
			}
		}
	}
	Display(badGroup);
}

void DisplayWithOverSum(vector<Abiturient>& group)
{
	vector<Abiturient> overSumGroup;

	int N = 0;
	cout << "Enter sum of scores(N = [0...300]): ";
	cin >> N;

	int sum;
	for (size_t i = 0; i < group.size(); i++)
	{
		sum = 0;

		vector<int> buffScores = group[i].GetScores();
		for (size_t j = 0; j < buffScores.size(); j++)
		{
			sum += buffScores[j];
		}

		if (sum >= N)
		{
			overSumGroup.push_back(group[i]);
		}
	}
	Display(overSumGroup);
}

void DisplayHighest(vector<Abiturient>& group)
{
	vector<Abiturient> highestGroup;
	vector<Abiturient> sortedGroup = group;
	int N = 0;
	cout << "Enter count of abiturients(N): ";
	cin >> N;

	int size = N >= group.size() ? group.size() : N;

	for (size_t i = 0; i < group.size(); i++)
	{
		for (size_t j = i + 1; j < group.size(); j++)
		{
			if (group[j].GetResult() > group[i].GetResult()) AbiturientSwap(group[j], group[i]);
		}
	}

	for (size_t j = 0; j < size; j++)
	{
		highestGroup.push_back(sortedGroup[j]);
	}
	Display(highestGroup);
}

void DisplayPassed(vector<Abiturient>& group)
{
	vector<Abiturient> passedGroup;
	int N = 0;
	cout << "Enter semi-pass score(N): ";
	cin >> N;

	for (size_t i = 0; i < group.size(); i++)
	{
		if (group[i].GetResult() >= N)
		{
			passedGroup.push_back(group[i]);
		}
	}
	Display(passedGroup);
}

void SystemFan()
{
	system("pause");
	system("cls");
}

void AbiturientSwap(Abiturient& abiturient1, Abiturient& abiturient2)
{
	Abiturient buffAbiturient(abiturient1.GetName(),
							  abiturient1.GetSurname(),
							  abiturient1.GetPatronymic(),
							  abiturient1.GetAdress(),
							  abiturient1.GetScores(),
							  abiturient1.GetMarks());
	abiturient1.SetAbiturient(abiturient2.GetName(),
							  abiturient2.GetSurname(),
							  abiturient2.GetPatronymic(),
							  abiturient2.GetAdress(),
							  abiturient2.GetScores(),
							  abiturient2.GetMarks());
	abiturient2.SetAbiturient(buffAbiturient.GetName(),
							  buffAbiturient.GetSurname(),
							  buffAbiturient.GetPatronymic(),
							  buffAbiturient.GetAdress(),
							  buffAbiturient.GetScores(),
							  buffAbiturient.GetMarks());
}

#endif