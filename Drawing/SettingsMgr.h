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
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
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

};
