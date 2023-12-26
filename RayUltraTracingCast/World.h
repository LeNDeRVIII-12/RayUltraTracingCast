#pragma once

#include <SFML/Graphics.hpp>
#include "Global.h"

class Player;
class Camera;

class World
{
private:
	Player* player;
	Camera* camera;

public:
	World(Player* player, Camera* camera);
//	int worldMap[mapWidth][mapHeight];
	int** worldMap;
	void editMap(int x, int y, int value);
//	void worldInit();
};