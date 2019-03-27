#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{

public:
	virtual void draw() = 0;
};

class Circle :public DrawingShape
{
private:
	
public:
	Circle()
	{
		
	}

	

	void draw()
	{
		
	}
};

class Square :public DrawingShape
{
public:
	Square()
	{

	}
};




