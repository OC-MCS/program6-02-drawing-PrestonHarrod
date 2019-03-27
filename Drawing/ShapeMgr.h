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
	vector<DrawingShape *> shapeList;
public:
	ShapeMgr()
	{

	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == 0)
		{
			Circle circle;
		}
	}

};
