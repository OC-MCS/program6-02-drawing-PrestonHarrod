#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color color;
	ShapeEnum shape;
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		color = startingColor;
		shape = startingShape;
	}

	Color getCurColor()
	{
		return color;
	}


	ShapeEnum getCurShape()
	{
		return shape;
	}

	void setColor(Color c)
	{
		color = c;
	}

	void setShape(ShapeEnum s)
	{
		shape = s;
	}

	void write(fstream &file)
	{
		unsigned c = getCurColor().toInteger();
		file.write(reinterpret_cast<char *>(&c), sizeof(c));
		if (getCurShape() == CIRCLE)
		{
			file.write(reinterpret_cast<char *>(CIRCLE), sizeof(CIRCLE));
		}
		else
		{
			file.write(reinterpret_cast<char *>(SQUARE), sizeof(SQUARE));
		}
	}

	void read(fstream &file)
	{
		file.seekg(0L, ios::beg);
		
	}
};