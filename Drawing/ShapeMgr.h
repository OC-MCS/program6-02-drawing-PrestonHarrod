#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.


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
		if (whichShape == CIRCLE)
		{
			Circle *circle = new Circle(pos, color);
			shapeList.push_back(circle);
		}
		else if (whichShape == SQUARE)
		{
			Square *square = new Square(pos, color);
			shapeList.push_back(square);

		}
	}

	void write(fstream &file)
	{
	
	}

	vector<DrawingShape *> returnList() const
	{
		vector<DrawingShape *> p = shapeList;
		return p;
	}

};
