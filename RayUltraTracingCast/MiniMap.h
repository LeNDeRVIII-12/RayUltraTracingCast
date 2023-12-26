#pragma once
#include <SFML/Graphics.hpp>

class Player;


class MiniMap
{
protected:
	friend class Player;
	double playerX, playerY;
	Player& player;

public:
	MiniMap(Player& player);

	void draw(sf::RenderTarget& window);
};
