#include <iostream>
#include "Entity.h"

void Entity::takeDamage()
{
	healthPoint -= 35;
	std::cout << healthPoint << std::endl;
}

void Entity::checkIsDeath()
{
	if (healthPoint <= 0)
		isDeath = true;
}

std::vector<double> Entity::getDir()
{
	return { dirX, dirY };
}

std::vector<double> Entity::getPlane()
{
	return { planeX, planeY };
}

std::vector<double> Entity::getPos()
{
	return { posX, posY };
}

double Entity::getMoveSpeed()
{
	return moveSpeed;
}