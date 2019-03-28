#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	Vector2f pos;
	RectangleShape squareBtn;

public:
	DrawingUI(Vector2f p)
	{
		pos = p;
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		squareBtn.setPosition(pos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(500, 500));
		squareBtn.setFillColor(Color::Transparent);
		win.draw(squareBtn);

		vector<DrawingShape *> shap;
		shap = mgr->returnList();
		if (shap.size() != 0)
		{
			for (int i = 0; i < shap.size(); i++)
			{
				shap[i]->draw(win);
			}
		}
		
		

	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool thing = false;
		if (squareBtn.getGlobalBounds().contains(mousePos))
		{
			thing = true;
			cout << "In";
		}
		return thing;
	}

};

