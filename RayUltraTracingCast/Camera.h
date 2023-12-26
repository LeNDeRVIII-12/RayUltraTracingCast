#pragma once

class Player;

class Camera
{
private:
	Player& player;

public:
	Camera(Player& player) : player(player) {}

	void castRays(sf::RenderWindow& window);
};