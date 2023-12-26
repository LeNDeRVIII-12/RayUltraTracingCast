#include "MiniMap.h"
#include "Player.h"
#include "Camera.h"
#include "World.h"
#include "Enemy.h"
#include "Key.h"
#include "Global.h"

MiniMap::MiniMap(Player& player) : player(player)
{
	playerX = player.getPos()[0];
	playerY = player.getPos()[1];
}

void MiniMap::draw(sf::RenderTarget& window)
{
	int counter = mapHeight + mapWidth;
	sf::Vector2f size(10.0f, 10.0f);
	sf::RectangleShape* wall = new sf::RectangleShape[counter];
	sf::RectangleShape playerMap(sf::Vector2f(10.0f, 10.0f));
	playerMap.setFillColor(sf::Color::Cyan);

	playerX = player.getPos()[0];
	playerY = player.getPos()[1];

	for (int i = 0; i < mapWidth; ++i)
	{
		for (int j = 0; j < mapHeight; ++j)
		{
			switch (world->worldMap[i][j])
			{
			case 0:
				wall[j].setFillColor(sf::Color::Black);
				break;
			case 1:
				wall[j].setFillColor(sf::Color::Red);
				break;
			case 2:
				wall[j].setFillColor(sf::Color::Green);
				break;
			case 3:
				wall[j].setFillColor(sf::Color::Blue);
				break;
			case 4:
				wall[j].setFillColor(sf::Color::White);
				break;
			default:
				wall[j].setFillColor(sf::Color::Yellow);
				break;
			}

			//playerMap.setPosition(static_cast<int>(playerX) * 10, static_cast<int>(playerY) * 10);

			playerMap.setPosition(playerX * 9.5, playerY * 9.5);

			wall[j].setPosition(i * 10, j * 10);
			wall[j].setSize(size);
			window.draw(playerMap);
			window.draw(wall[j]);
		}
	}
	delete[] wall;
}