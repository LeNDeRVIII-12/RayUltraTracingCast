#pragma once
#include <vector>

class Weapon;

class Entity
{
protected:
	double posX, posY;
	double dirX, dirY;
	double planeX, planeY;
	double moveSpeed;
	double rotSpeed;
	Weapon* usingWeapon;
	bool isDeath;

	int healthPoint;

	void takeDamage();
	void giveDamage();

	void checkIsDeath();

public:
	Entity(double posX, double poxY, double dirX, double dirY, double planeX, double planeY, double moveSpeed,
		double rotSpeed, Weapon* weapon, bool isDeath, int healthPoint) : posX(posX), posY(poxY), dirX(dirX), dirY(dirY), planeX(planeX),
		planeY(planeY), moveSpeed(moveSpeed), rotSpeed(rotSpeed), usingWeapon(weapon), isDeath(isDeath), healthPoint(healthPoint) {}


	std::vector<double> getDir();

	std::vector<double> getPlane();

	std::vector<double> getPos();

	double getMoveSpeed();

};
