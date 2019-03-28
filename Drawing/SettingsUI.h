#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	Color color;
	ShapeEnum shape;
	CircleShape blueBtn;
	CircleShape redBtn;
	CircleShape green;
	CircleShape circleBtn;
	RectangleShape squareBtn;

	bool make = false;

public:
	SettingsUI(SettingsMgr *mgr)
	{
		color = mgr->getCurColor();
		shape = mgr->getCurShape();
	}

	void handleMouseUp(Vector2f mouse, SettingsMgr *mgr)
	{
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			mgr->setColor(Color::Blue);
			blueBtn.setFillColor(Color::Blue);
			redBtn.setFillColor(Color::Transparent);
			green.setFillColor(Color::Transparent);
			make = true;
		}
		else if (redBtn.getGlobalBounds().contains(mouse))
		{
			mgr->setColor(Color::Red);
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Red);
			green.setFillColor(Color::Transparent);
			make = true;
		}
		else if (green.getGlobalBounds().contains(mouse))
		{
			mgr->setColor(Color::Green);
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			green.setFillColor(Color::Green);
			make = true;
		}

		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			mgr->setShape(CIRCLE);
			circleBtn.setFillColor(Color::White);
			squareBtn.setFillColor(Color::Transparent);
			make = true;
		}
		else if (squareBtn.getGlobalBounds().contains(mouse))
		{
			mgr->setShape(SQUARE);
			circleBtn.setFillColor(Color::Transparent);
			squareBtn.setFillColor(Color::White);
			make = true;
		}

	}

	void draw(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");
		Text title("Drawing Color", font, 25);
		Text title2("Drawing Shape", font, 25);
		title.setPosition(30, 25);
		title2.setPosition(30, 300);
		win.draw(title);
		win.draw(title2);

		Vector2f pos(100, 75);
		Vector2f pos2(100, 125);
		Vector2f pos3(100, 175);
		blueBtn.setPosition(pos);
		redBtn.setPosition(pos2);
		green.setPosition(pos3);

		blueBtn.setRadius(10);
		redBtn.setRadius(10);
		green.setRadius(10);

		blueBtn.setOutlineThickness(2);
		redBtn.setOutlineThickness(2);
		green.setOutlineThickness(2);

		blueBtn.setOutlineColor(Color::Blue);
		redBtn.setOutlineColor(Color::Red);
		green.setOutlineColor(Color::Green);
		win.draw(blueBtn);
		win.draw(redBtn);
		win.draw(green);

		Vector2f pos4(100, 400);
		circleBtn.setPosition(pos4);
		circleBtn.setRadius(10);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);

		Vector2f sqPos(100, 350);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(20, 20));

		win.draw(circleBtn);
		win.draw(squareBtn);

		if (color == Color::Blue && !make)
		{
			blueBtn.setFillColor(Color::Blue);
			redBtn.setFillColor(Color::Transparent);
			green.setFillColor(Color::Transparent);
		}
		if (color == Color::Red && !make)
		{
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Red);
			green.setFillColor(Color::Transparent);
		}
		if (color == Color::Green && !make)
		{
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			green.setFillColor(Color::Green);
		}
		if (shape == 0 && !make)
		{
			circleBtn.setFillColor(Color::White);
			squareBtn.setFillColor(Color::Transparent);
		}
		if (shape == 1)
		{
			circleBtn.setFillColor(Color::Transparent);
			squareBtn.setFillColor(Color::White);
		}

	}

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}


};
