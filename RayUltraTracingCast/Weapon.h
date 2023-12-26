#pragma once

#include <SFML/Graphics.hpp>

enum WeaponType
{
	Nothing,
	Hand,

};


class Weapon {
protected:
	sf::Texture T_weapon;
	sf::Sprite S_Weapon;
	double d_speed = 1;

	WeaponType type;
	int damage;


private:
public:
	Weapon(WeaponType weapon, int damage) : type(weapon), damage(damage) {};

	WeaponType getWeaponType();
};
