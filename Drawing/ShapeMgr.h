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
		for (int i = 0; i < shapeList.size(); i++)
		{
			Shapes s = shapeList[i]->getFileRecord();
			file.write(reinterpret_cast<char *>(&s), sizeof(s));
		}
		file.close();
	}

	void read(fstream &file)
	{
		Shapes s;
		while (file.read(reinterpret_cast<char *>(&s), sizeof(s)))
		{
			Vector2f a(s.x, s.y);
			Color aColor(s.color);
			addShape(a, s.shape, aColor);
		}
	}

	vector<DrawingShape *> returnList() const
	{
		vector<DrawingShape *> p = shapeList;
		return p;
	}

};
