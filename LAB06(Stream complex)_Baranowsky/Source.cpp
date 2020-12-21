#include "Complex.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void Menu();
void SystemFan();
void Enter(vector<Complex>&);
void Display(vector<Complex>&);
int MenuText();
void Test();
void EnterComplexVectors(vector<vector<Complex>>&);
void DisplayComplexVectors(vector<vector<Complex>>&);
void AddComplexVectors(vector<vector<Complex>>&);
void DisplayComplexVector(vector<Complex>&);
void WriteInFile(vector<vector<Complex>>&);
void ReadFromFile(vector<vector<Complex>>&);


int main()
{
	Menu();
}

void Menu()
{
	vector<Complex> group;
	vector<vector<Complex>> vectorGroup;
	enum
	{
		Enter_c = 1,
		Display_c,
		Test_c,
		Clear,
		EnterComplexVector_c,
		DisplayComplexVector_c,
		AddComplexVector_c,
		WriteInFile_c,
		ReadFromFile_c,
		Exit
	};

	while (true)
	{
		int key = MenuText();
		if (key == Exit)
			return;
		switch (key)
		{
		case Enter_c:
			Enter(group);
			SystemFan();
			break;
		case Display_c:
			Display(group);
			SystemFan();
			break;
		case Test_c:
			Test();
			SystemFan();
			break;
		case Clear:
			group.clear();
			SystemFan();
			break;
		case EnterComplexVector_c:
			EnterComplexVectors(vectorGroup);
			SystemFan();
			break;
		case DisplayComplexVector_c:
			DisplayComplexVectors(vectorGroup);
			SystemFan();
			break;
		case AddComplexVector_c:
			AddComplexVectors(vectorGroup);
			SystemFan();
			break;
		case WriteInFile_c:
			WriteInFile(vectorGroup);
			SystemFan();
			break;
		case ReadFromFile_c:
			ReadFromFile(vectorGroup);
			SystemFan();
			break;
		default:
			cout << "Invalid input! Enter number 1...4";
			break;
		}
	}
}

int MenuText()
{
	int key;
	cout << "\nEnter the number of operation:"
		"\n>> 1 - Enter Complexs"
		"\n>> 2 - Display Complexs"
		"\n>> 3 - Test operators"
		"\n>> 4 - Clear info"
		"\n>> 5 - Enter Complex vectors"
		"\n>> 6 - Display Complex vectors"
		"\n>> 7 - Add Complex vectors"
		"\n>> 8 - Write data in file"
		"\n>> 9 - Read data from file"
		"\n>> 10 - EXIT\n>> ";
	cin >> key;
	SystemFan();
	return key;
}

void Enter(vector<Complex>& group)
{
	bool flag = true;
	while (flag)
	{
		Complex buffComplex;
		buffComplex.EnterComplex();
		group.push_back(buffComplex);

		cout << "Do you want to write in new Complex ?"
			<< "\n1 >> Yes"
			<< "\n0 >> No\n";
		cin >> flag;
		SystemFan();
		if (!flag)
			return;
	}
}

void Display(vector<Complex>& group)
{
	cout << endl;
	for (size_t i = 0; i < group.size(); i++)
	{
		cout << "#" << i + 1 << " ";
		group[i].Display();
		cout << ";\n";
	}
}

void Test()
{
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	cout << "Enter real part of complex number A: ";
	cin >> x1;
	cout << "Enter imaginary part of complex number A: ";
	cin >> y1;
	cout << "Enter real part of complex number B: ";
	cin >> x2;
	cout << "Enter imaginary part of complex number B: ";
	cin >> y2;

	Complex a(x1, y1);
	cout << "A >> ";
	a.Display();
	cout << endl;
	Complex b(x2, y2);
	cout << "B >> ";
	b.Display();
	cout << endl;
	Complex c = a + b;
	cout << "A + B >> ";
	c.Display();
	cout << endl;
	c = a - b;
	cout << "A - B >> ";
	c.Display();
	cout << endl;
	c = a * b;
	cout << "A * B >> ";
	c.Display();
	cout << endl;
	c = a / b;
	cout << "A / B >> ";
	c.Display();
	cout << endl;
}

void SystemFan()
{
	system("pause");
	system("cls");
}

void EnterComplexVectors(vector<vector<Complex>>& vectorGroup)
{
	bool flag1 = true;
	bool flag2;

	while (flag1)
	{
		cout << "Do you want to add new complex vector ?"
			<< "\n1 >> Yes"
			<< "\n0 >> No\n";
		cin >> flag2;
		SystemFan();
		if (!flag2) return;
		vector<Complex> buffVector;
		while (flag2)
		{
			Complex buffComplex;
			buffComplex.EnterComplex();
			buffVector.push_back(buffComplex);

			cout << "Do you want to write in new Complex ?"
				<< "\n1 >> Yes"
				<< "\n0 >> No\n";
			cin >> flag2;
			SystemFan();
			if (!flag2)
				break;
		}
		vectorGroup.push_back(buffVector);
	}
}

void DisplayComplexVectors(vector<vector<Complex>>& vectorGroup)
{
	for (size_t i = 0; i < vectorGroup.size(); i++)
	{
		cout << "\nComplex vector #" << i + 1 << ":\n";
		cout << "(";
		for (size_t j = 0; j < vectorGroup[i].size(); j++)
		{
			if (j == vectorGroup[i].size() - 1)
			{
				vectorGroup[i][j].Display();
				break;
			}
			else
			{
				vectorGroup[i][j].Display();
				cout << ", ";
			}
		}
		cout << ")\n";
	}
}

void AddComplexVectors(vector<vector<Complex>>& vectorGroup)
{
	size_t vectorIndex1 = 0, vectorIndex2 = 0;
	while (true)
	{
		while (true)
		{
			cout << "\nEnter indexes of vectors that you want to add";
			cout << "\nThey can be only from 1 to " << vectorGroup.size();
			cout << "\nYou can exit by entering 0 :)";
			cout << "\nFirst index: ";
			cin >> vectorIndex1;
			if (vectorIndex1 == 0) return;
			if (vectorIndex1 > vectorGroup.size() || vectorIndex1 <= 0)
			{
				cout << "Please enter correct index!\n";
				SystemFan();
				continue;
			}
			vectorIndex1--;

			cout << "\nSecond index: ";
			cin >> vectorIndex2;
			if (vectorIndex2 == 0) return;
			if (vectorIndex2 > vectorGroup.size() || vectorIndex2 <= 0)
			{
				cout << "Please enter correct index!\n";
				SystemFan();
				continue;
			}
			vectorIndex2--;
			break;
		}

		if (vectorGroup[vectorIndex1].size() != vectorGroup[vectorIndex2].size())
		{
			cout << "Only vectors of equal size can be added!";
			SystemFan();
			continue;
		}

		vector<Complex> buffGroup;
		for (size_t i = 0; i < vectorGroup[vectorIndex1].size(); i++)
		{
			buffGroup.push_back(vectorGroup[vectorIndex1][i] + vectorGroup[vectorIndex2][i]);
		}
		cout << "\nResult of adding\n";
		cout << "#1: ";
		DisplayComplexVector(vectorGroup[vectorIndex1]);
		cout << "#2: ";
		DisplayComplexVector(vectorGroup[vectorIndex2]);
		cout << "IS: ";
		DisplayComplexVector(buffGroup);

		bool flag;
		cout << "\nDo you want to add another complex vectors ?"
			<< "\n1 >> Yes"
			<< "\n0 >> No\n";
		cin >> flag;
		if (!flag) return;
		SystemFan();
	}
}

void DisplayComplexVector(vector<Complex>& buffGroup)
{
	cout << "(";
	for (size_t j = 0; j < buffGroup.size(); j++)
	{
		if (j == buffGroup.size() - 1)
		{
			buffGroup[j].Display();
			break;
		}
		else
		{
			buffGroup[j].Display();
			cout << ", ";
		}
	}
	cout << ")\n";
}

void WriteInFile(vector<vector<Complex>>& vectorGroup)
{
	string path = "";
	cout << "Where do you want to save your data?(write in format (filename).txt)\n>> ";
	cin >> path;
	SystemFan();

	ofstream fout(path, ios::app | ios::binary);

	if (!fout.is_open())
	{
		cout << "Something went wrong :(" << endl;
	}
	else
	{
		cout << "File was opened!" << endl;

		for (size_t i = 0; i < vectorGroup.size(); i++)
		{
			size_t buffSize = vectorGroup[i].size();
			fout.write((char*)&buffSize, sizeof(size_t));

			for (size_t j = 0; j < vectorGroup[i].size(); j++)
			{
				fout.write((char*)&vectorGroup[i][j], sizeof(Complex));
			}
		}
		cout << "Write operation was successful!" << endl;
	}

	fout.close();
}

void ReadFromFile(vector<vector<Complex>>& vectorGroup)
{
	string path = "";
	cout << "Where do you want to read the information?\n>> ";
	cin >> path;
	SystemFan();

	ifstream fin;
	fin.open(path, ios::binary);

	if (!fin.is_open())
	{
		cout << "Something went wrong :(" << endl;
	}
	else
	{
		cout << "File was opened!" << endl;

		Complex buffComplex;
		vector<Complex> buffVector;

		while (true)
		{
			size_t buffSize = 0;

			if (!fin.read((char*)&buffSize, sizeof(size_t))) break;

			cout << "Size = " << buffSize << endl;

			for (size_t i = 0; i < buffSize; i++)
			{
				fin.read((char*)&buffComplex, sizeof(Complex));
				buffComplex.Display();
				cout << endl;
				buffVector.push_back(buffComplex);
			}
			
			vectorGroup.push_back(buffVector);
			buffVector.clear();
		}
		cout << "Read operation was successful!" << endl;
	}

	fin.close();
}
