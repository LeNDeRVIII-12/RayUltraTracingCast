#include "Player.h"
#include "MiniMap.h"
#include "Global.h"
#include "Object2D.h"
#include "Camera.h"
#include "World.h"
#include "Enemy.h"
#include "Key.h"
#include "Weapon.h"

Player::Player(double posX, double posY, double dirX, double dirY, double planeX, double planeY, double moveSpeed,
	double rotSpeed, Weapon* weapon, bool isDeath, Enemy* enemy, Key* key, int healthPoint)
	: Entity(posX, posY, dirX, dirY, planeX, planeY, moveSpeed, rotSpeed, weapon, isDeath, healthPoint), enemys(enemy), key(key), d_frameDuraction(0.1),
	i_currentFrame(0), i_frameCount(9), d_elapsedTime(0.0)
{
	if (!T_Hand.loadFromFile("hand_idle.png"))
	{
		printf("eror");

	}
	S_Hand.setTexture(T_Hand);
}

void Player::giveDamage()
{
	int x = static_cast<int>(posX);
	int y = static_cast<int>(posY);

	if (usingWeapon->getWeaponType() == Hand)
	{
		static sf::Clock refresh;
		if (world->worldMap[x + 1][y] == -11 || world->worldMap[x - 1][y] == -11 ||
			world->worldMap[x + 1][y + 1] == -11 || world->worldMap[x - 1][y + 1] == -11 ||
			world->worldMap[x + 1][y - 1] == -11 || world->worldMap[x - 1][y - 1] == -11 ||
			world->worldMap[x][y + 1] == -11 || world->worldMap[x][y - 1] == -11)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && refresh.getElapsedTime().asMilliseconds() > 300)
			{
				enemys->takeDamage();
				refresh.restart();
			}
		}
	}
}

void Player::pickUp()
{
	if (static_cast<int>(key->getPos()[0] == static_cast<int>(posX)) && static_cast<int>(key->getPos()[1] == static_cast<int>(posY)))
	{
		key->isPickingUp = 1;
	}
}

void Player::move(double deltaTime)
{
	double moveSpeed = deltaTime * 5.0;
	double rotSpeed = deltaTime * 3.0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (world->worldMap[static_cast<int>(posX + dirX * moveSpeed)][static_cast<int>(posY)] == 0)
			posX += dirX * moveSpeed;

		if (world->worldMap[static_cast<int>(posX)][static_cast<int>(posY + dirY * moveSpeed)] == 0)
			posY += dirY * moveSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (world->worldMap[static_cast<int>(posX - dirX * moveSpeed)][static_cast<int>(posY)] == 0)
			posX -= dirX * moveSpeed;

		if (world->worldMap[static_cast<int>(posX)][static_cast<int>(posY - dirY * moveSpeed)] == 0)
			posY -= dirY * moveSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		double oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		double oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
}

void Player::update(double dt) {
	d_elapsedTime += dt;
	if (d_elapsedTime >= d_frameDuraction) {

		i_currentFrame = (i_currentFrame + 1) % i_frameCount;
		S_Hand.setTextureRect(sf::IntRect(i_currentFrame * frameWidth, 0, frameWidth, frameHeight));
		d_elapsedTime = 0.0;
	}
};

void Player::draw(sf::RenderTarget& window)
{
	window.draw(S_Hand);
};