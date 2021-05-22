#include <iostream>
#include "Shape.h"

using namespace std;

int main() 
{
	Square square(2, 2, 4);
	square.Show();
	square.Move(0, 0);
	square.Move(2, 0);
	square.Show();
	square.Draw();

	system("pause");
	system("cls");

	Circle circle(0, 0, 4);
	circle.Show();
	circle.Move(0, 2);
	circle.Move(-2, -2);
	circle.Show();
	circle.Draw();
	
	system("pause");
	system("cls");

	Ellipse ellipse(-3, 2, 3, -2);
	ellipse.Show();
	ellipse.Move(5, 2);
	ellipse.Move(-5, -4);
	ellipse.Show();
	ellipse.Draw();
	
	system("pause");
	system("cls");
}