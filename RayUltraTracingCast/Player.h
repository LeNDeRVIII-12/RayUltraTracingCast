#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Entity;
class Enemy;
class Key;
class Weapon;

class Player : public Entity
{
private:
	double d_elapsedTime;
	double d_frameDuraction;
	int i_frameCount;
	int i_currentFrame;
	int frameWidth = 960;
	int frameHeight = 1280;

	Enemy* enemys;
	Key* key;

	sf::Texture T_Hand;
	sf::Sprite S_Hand;

public:
	Player(double posX, double posY, double dirX, double dirY, double planeX, double planeY, double moveSpeed,
		double rotSpeed, Weapon* weapon, bool isDeath, Enemy* enemy, Key* key, int healthPoint);

	void giveDamage();

	void pickUp();

	void move(double deltaTime);

	void update(double dt);

	void draw(sf::RenderTarget& window);
};