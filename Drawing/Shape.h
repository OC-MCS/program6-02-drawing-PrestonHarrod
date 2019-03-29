#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

struct Shapes
{
	float x;
	float y;
	int color;
	ShapeEnum shape;
};

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	
public:
	DrawingShape()
	{

	}
	virtual void draw(RenderWindow&) = 0;
	virtual Shapes getFileRecord() = 0;
};

class Circle :public DrawingShape
{
private:
	CircleShape circle;
	Vector2f position;
	Color color;
	float radius = 10;
public:
	Circle(Vector2f p, Color col)
	{
		position = p;
		color = col;
		circle.setPosition(p);
		circle.setRadius(radius);
		circle.setFillColor(col);
	}

	void draw(RenderWindow &win)
	{
		win.draw(circle);
	}

	
	Shapes getFileRecord()
	{
		Shapes s;
		unsigned i = color.toInteger();
		s.color = i;
		s.shape = CIRCLE;
		s.x = position.x;
		s.y = position.y;

		return s;
	}
	
};

class Square :public DrawingShape
{
private:
	RectangleShape square;
	Vector2f position;
	ShapeEnum shape;
	Color color;
public:

	Square(Vector2f p,  Color col)
	{
		position = p;
		color = col;
		square.setSize(Vector2f(20,20));
		square.setPosition(p);
		square.setFillColor(col);
	}

	void draw(RenderWindow &win)
	{
		win.draw(square);
	}
	
	Shapes getFileRecord()
	{
		Shapes s;
		unsigned i = color.toInteger();
		s.color = i;
		s.shape = SQUARE;
		s.x = position.x;
		s.y = position.y;

		return s;
	}
	
	

};

// add Circle, Square classes below. These are derived from DrawingShape



