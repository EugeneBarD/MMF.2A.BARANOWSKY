#include "Abiturient.h"
#include "Display.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void Menu();
void Enter(vector<Abiturient>&);
int MenuText();

int main()
{
    Menu();
}

void Menu()
{
    vector<Abiturient> group;
    enum
    {
        Enter_c = 1,
        Display_c,
        Clear,
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
            DisplayMenu(group);
            SystemFan();
            break;
        case Clear:
            group.clear();
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
        "\n>> 1 - Enter abiturients"
        "\n>> 2 - Display abiturients"
        "\n>> 3 - Clear info"
        "\n>> 4 - EXIT\n>> ";
    cin >> key;
    SystemFan();
    return key;
}

void Enter(vector<Abiturient>& group)
{
    bool flag = true;
    while (flag)
    {
        Abiturient buffAbiturient;
        buffAbiturient.EnterAbiturient();
        group.push_back(buffAbiturient);

        cout << "Do you want to write in new abiturient ?"
            << "\n1 >> Yes"
            << "\n0 >> No\n";
        cin >> flag;
        SystemFan();
        if (!flag)
            return;
    }
}