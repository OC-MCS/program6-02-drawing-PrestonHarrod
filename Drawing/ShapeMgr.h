#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

struct Shapes
{
	Vector2f positon;
	int color;
	ShapeEnum shape;
};

class ShapeMgr
{
private:
	vector<Shapes *> shapeList;
public:
	ShapeMgr()
	{

	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		Shapes *shape;
		unsigned colorNumber = color.toInteger();
		shape->color = colorNumber;
		shape->shape = whichShape;
		shape->positon = pos;
		shapeList.push_back(shape);
	}

};
