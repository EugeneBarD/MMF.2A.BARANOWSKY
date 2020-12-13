#include <iostream>
#include <vector>
#include "CharStack.h"

using namespace std;

void Menu();
int MenuText();
void SystemFan();
void Enter(vector<Stack*>&);
void Display(vector<Stack*>&);
void SizesSum(vector<Stack*>&);

int main()
{
	Menu();
}

void Menu()
{
	vector<Stack*> group;
	enum
	{
		Enter_c = 1,
		Display_c,
		Clear,
		SizesSum_c,
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
		case Clear:
			group.clear();
			SystemFan();
			break;
		case SizesSum_c:
			SizesSum(group);
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
		"\n>> 1 - Enter Stack"
		"\n>> 2 - Display Complexs"
		"\n>> 3 - Clear info"
		"\n>> 4 - Sum of sizes of stacks"
		"\n>> 5 - EXIT\n>> ";
	cin >> key;
	SystemFan();
	return key;
}

void SystemFan()
{
	system("pause");
	system("cls");
}

void Enter(vector<Stack*>& group)
{
	bool flag = true;
	char symbol = ' ';
	while (flag)
	{
		Stack* buffStack = new Stack;
		while (true)
		{
			cout << "Enter symbol: ";
			cin >> symbol;

			(*buffStack).Push_back(symbol);

			bool key = true;
			cout << "Do you want to add new member?\n"
				<< "1 >> Yes\n"
				<< "0 >> No\n";
			cin >> key;
			SystemFan();
			if (!key)
				break;
		}
		group.push_back(buffStack);

		cout << "Do you want to write in new Stack ?"
			<< "\n1 >> Yes"
			<< "\n0 >> No\n";
		cin >> flag;
		SystemFan();
		if (!flag)
			return;
	}
}

void Display(vector<Stack*>& group)
{
	for (size_t i = 0; i < group.size(); i++)
	{
		cout << i + 1 << "# ";
		(*group[i]).Display();
		cout << endl;
	}
}

void SizesSum(vector<Stack*>& group) 
{
	int sizesSum = 0;
	for (size_t i = 0; i < group.size(); i++)
	{
		cout << i + 1 << "# Stack size: " << (*group[i]).GetSize() << endl;
		sizesSum += (*group[i]).GetSize();
	}
	cout << "Sum of sizes of stacks is equal to " << sizesSum;
}