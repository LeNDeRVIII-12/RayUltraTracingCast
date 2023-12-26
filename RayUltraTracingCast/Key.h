#pragma once
#include <SFML/Graphics.hpp>
#include "Object2D.h"

class Player;
class Object2D;

class Key : public Object2D
{
protected:
	friend class Player;
	int wallID_x, wallID_y;
	bool isPickingUp;

	sf::Texture T_Key;
	sf::Sprite S_Key;

	void open();

public:
	Key(double x, double y, int openX, int openY, bool is) : Object2D(x, y), wallID_x(openX), wallID_y(openY), isPickingUp(is) {}

	bool getPicked();

	void draw(sf::RenderTarget& window);
};