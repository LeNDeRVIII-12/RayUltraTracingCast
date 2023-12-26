#include "World.h"
#include "fstream"
#include "iostream"

World::World(Player* player, Camera* camera) : player(player), camera(camera)
{
	std::ifstream file("map1.txt");

	if (!file.is_open())
	    return;

	worldMap = new int* [mapWidth];

	for (int i = 0; i < mapWidth; ++i)
	{
	    worldMap[i] = new int[mapHeight];

	    for (int j = 0; j < mapHeight; ++j)
	    {
	        if (!(file >> worldMap[i][j]))
	            return;
	    }
	}

	file.close();

	/*std::ifstream file("map1.txt");

	if (!file.is_open())
		return;

	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			if (!(file >> worldMap[i][j]))
				return;
		}
	}

	file.close();*/
}

void World::editMap(int x, int y, int value)
{
	if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight)
	{
		worldMap[x][y] = value;
	}
	else
	{
		return;
	}
}