#pragma once
class Shape
{
public:
	virtual void Draw() = 0;
	virtual void Move(int, int) = 0;
	virtual void Show() = 0;
};

class Square : public Shape 
{
public:
	Square(int,int,int);
	void Draw() override;
	void Move(int, int) override;
	void Show() override;
private:
	int x, y, side;
};

class Circle : public Shape
{
public:
	Circle(int, int, int);
	void Draw() override;
	void Move(int, int) override;
	void Show() override;
private:
	int x, y, radius;
};

class Ellipse : public Shape
{
public:
	Ellipse(int, int, int, int);
	void Draw() override;
	void Move(int, int) override;
	void Show() override;
private:
	int x1, y1, x2, y2;
};
