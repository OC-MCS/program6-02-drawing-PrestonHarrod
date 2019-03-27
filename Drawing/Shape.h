#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
public:
	DrawingShape()
	{

	}
	virtual void draw(RenderWindow&) = 0;
	virtual Shapes getRecordFile() = 0;
};

class Circle :public DrawingShape
{
private:
	CircleShape circle;
public:
	void draw(RenderWindow &win) 
	{
		win.draw(circle);
	}

	Shapes getRecordfile(Shapes other)
	{
		return other;
	}
};

class Square :public DrawingShape
{
private:
	RectangleShape square;
public:
	void draw(RenderWindow &win)
	{
		win.draw(square);
	}

	Shapes getRecordFile(Shapes other)
	{
		return other;
	}
};

// add Circle, Square classes below. These are derived from DrawingShape



