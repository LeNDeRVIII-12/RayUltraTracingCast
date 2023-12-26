#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Object2D
{
protected:
	double posX, posY;
public:
	Object2D(double x, double y) : posX(x), posY(y) {}

	void draw() {}
	std::vector<double> getPos();
};