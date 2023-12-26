#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "Player.h"
#include "Global.h"

void Camera::castRays(sf::RenderWindow& window)
{
	double dirX = player.getDir()[0];
	double dirY = player.getDir()[1];

	double planeX = player.getPlane()[0];
	double planeY = player.getPlane()[1];

	double posX = player.getPos()[0];
	double posY = player.getPos()[1];

	for (int x = 0; x < screenWidth; x++)
	{
		double cameraX = 2 * x / static_cast<double>(screenWidth) - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = static_cast<int>(posX);
		int mapY = static_cast<int>(posY);

		double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);

		double sideDistX, sideDistY;
		int stepX, stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (world->worldMap[mapX][mapY] > 0)
				hit = 1;
		}

		double perpWallDist;
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		int lineHeight = static_cast<int>(screenHeight / perpWallDist);
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;

		sf::VertexArray line(sf::Lines, 2);
		line[0].position = sf::Vector2f(x, drawStart);
		line[1].position = sf::Vector2f(x, drawEnd);
		sf::Color color;
		switch (world->worldMap[mapX][mapY])
		{
		case 1: color = sf::Color::Red; break;
		case 2: color = sf::Color::Green; break;
		case 3: color = sf::Color::Blue; break;
		case 4: color = sf::Color::White; break;
		default: color = sf::Color::Yellow; break;
		}

		if (side == 1)
		{
			color.r /= 2;
			color.g /= 2;
			color.b /= 2;
		}

		line[0].color = color;
		line[1].color = color;

		window.draw(line);
	}
}