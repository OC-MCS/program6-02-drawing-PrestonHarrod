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
		file.clear();
		file.seekp(0L, ios::beg);
		unsigned c = getCurColor().toInteger();
		file.write(reinterpret_cast<char *>(&c), sizeof(c));
		ShapeEnum a = CIRCLE;
		ShapeEnum b = SQUARE;
		if (getCurShape() == CIRCLE)
		{
			file.write(reinterpret_cast<char *>(&a), sizeof(a));
		}
		else
		{
			file.write(reinterpret_cast<char *>(&b), sizeof(b));
		}
	}

	void read(fstream &file)
	{

		file.seekp(0, ios::end);
		size_t size = file.tellg();
		if (size == 0)
		{
			setColor(Color::Blue);
			setShape(CIRCLE);
		}
		else {
		int colorNumber;
		ShapeEnum s;
		file.seekg(0L, ios::beg);
		file.read(reinterpret_cast<char *>(&colorNumber), sizeof(colorNumber));
		Color aColor(colorNumber);
		setColor(aColor);
		file.read(reinterpret_cast<char *>(&s), sizeof(s));
		setShape(s);
		}
		
	}
};