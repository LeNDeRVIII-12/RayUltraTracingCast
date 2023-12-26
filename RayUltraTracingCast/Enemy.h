#pragma once
#include "Entity.h"
class Entity;
class Weapon;
class Player;

class Enemy : public Entity
{
	friend class Player;

public:
	Enemy(double posX, double posY, double dirX, double dirY, double planeX, double planeY, double moveSpeed,
		double rotSpeed, Weapon* weapon, bool isDeath, int healthPoint) : Entity(posX, posY, dirX, dirY, planeX, planeY, moveSpeed, rotSpeed, weapon, isDeath, healthPoint) {}

};