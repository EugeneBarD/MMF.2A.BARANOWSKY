#include <windows.h>
#include <iostream>
#include "Shape.h"

using namespace std;

Square::Square(int x, int y, int side)
{
	this->x = x;
	this->y = y;
	this->side = side;
}

void Square::Draw()
{
	cout << "Square was drawn!" << endl;
}

void Square::Move(int x, int y)
{
	this->x += x;
	this->y += y;
	if (x > 0 && y > 0) 
	{
		cout << "Square was moved to the right by " << x << " and up by " << y << endl;
	}
	if (x < 0 && y > 0) 
	{
		cout << "Square was moved to the left by " << x << " and up by " << y << endl;
	}
	if (x < 0 && y < 0)
	{
		cout << "Square was moved to the left by " << x << " and down by " << y << endl;
	}
	if (x > 0 && y < 0)
	{
		cout << "Square was moved to the right by " << x << " and down by " << y << endl;
	}
	if (x == 0 && y == 0)
	{
		cout << "Square was not moved" << endl;
	}
	if (x > 0 && y == 0)
	{
		cout << "Square was moved to the right by " << x << endl;
	}
	if (x < 0 && y == 0)
	{
		cout << "Square was moved to the left by " << x << endl;
	}
	if (x == 0 && y > 0)
	{
		cout << "Square was moved up by " << y << endl;
	}
	if (x == 0 && y < 0)
	{
		cout << "Square was moved down by " << y << endl;
	}
}

void Square::Show()
{
	cout << "\nCoordinates of vertexs of square:\n";
	cout << "\tVertex #1: x = " << this->x << ", y = " << this->y << endl;
	cout << "\tVertex #2: x = " << this->x + this->side << ", y = " << this->y << endl;
	cout << "\tVertex #3: x = " << this->x + this->side << ", y = " << this->y - this->side << endl;
	cout << "\tVertex #4: x = " << this->x << ", y = " << this->y - this->side << endl;
	cout << "Side of square: side = " << this->side << "\n\n";
}

Circle::Circle(int x, int y, int radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;
}

void Circle::Draw()
{
	cout << "Circle was drawn!" << endl;
}

void Circle::Move(int x, int y)
{
	this->x += x;
	this->y += y;

	if (x > 0 && y > 0)
	{
		cout << "Circle was moved to the right by " << x << " and up by " << y << endl;
	}
	if (x < 0 && y > 0)
	{
		cout << "Circle was moved to the left by " << x << " and up by " << y << endl;
	}
	if (x < 0 && y < 0)
	{
		cout << "Circle was moved to the left by " << x << " and down by " << y << endl;
	}
	if (x > 0 && y < 0)
	{
		cout << "Circle was moved to the right by " << x << " and down by " << y << endl;
	}
	if (x == 0 && y == 0)
	{
		cout << "Circle was not moved" << endl;
	}
	if (x > 0 && y == 0)
	{
		cout << "Circle was moved to the right by " << x << endl;
	}
	if (x < 0 && y == 0)
	{
		cout << "Circle was moved to the left by " << x << endl;
	}
	if (x == 0 && y > 0)
	{
		cout << "Circle was moved up by " << y << endl;
	}
	if (x == 0 && y < 0)
	{
		cout << "Circle was moved down by " << y << endl;
	}
}

void Circle::Show()
{
	cout << "\nCoordinates of center of circle:\n";
	cout << "\tCenter: x = " << this->x << ", y = " << this->y << endl;
	cout << "Radius of circle: r = " << this->radius << "\n\n";
}

Ellipse::Ellipse(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void Ellipse::Draw()
{
	cout << "Ellipse was drawn!" << endl;
}

void Ellipse::Move(int x, int y)
{
	this->x1 += x;
	this->y1 += y;
	this->x2 += x;
	this->y2 += y;

	if (x > 0 && y > 0)
	{
		cout << "Ellipse was moved to the right by " << x << " and up by " << y << endl;
	}
	if (x < 0 && y > 0)
	{
		cout << "Ellipse was moved to the left by " << x << " and up by " << y << endl;
	}
	if (x < 0 && y < 0)
	{
		cout << "Ellipse was moved to the left by " << x << " and down by " << y << endl;
	}
	if (x > 0 && y < 0)
	{
		cout << "Ellipse was moved to the right by " << x << " and down by " << y << endl;
	}
	if (x == 0 && y == 0)
	{
		cout << "Ellipse was not moved" << endl;
	}
	if (x > 0 && y == 0)
	{
		cout << "Ellipse was moved to the right by " << x << endl;
	}
	if (x < 0 && y == 0)
	{
		cout << "Ellipse was moved to the left by " << x << endl;
	}
	if (x == 0 && y > 0)
	{
		cout << "Ellipse was moved up by " << y << endl;
	}
	if (x == 0 && y < 0)
	{
		cout << "Ellipse was moved down by " << y << endl;
	}
}

void Ellipse::Show()
{
	cout << "\nCoordinates of vertexs of rectangle of ellipse:\n";
	cout << "\tVertex #1: x = " << this->x1 << ", y = " << this->y1 << endl;
	cout << "\tVertex #2: x = " << this->x2 << ", y = " << this->y1 << endl;
	cout << "\tVertex #3: x = " << this->x2 << ", y = " << this->y2 << endl;
	cout << "\tVertex #4: x = " << this->x1 << ", y = " << this->y2 << "\n\n";
}