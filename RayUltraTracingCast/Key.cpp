#include "Key.h"
#include "Object2D.h"
#include "Global.h"
#include "Player.h"

void Key::open()
{
	/*	if (this == nullptr)
			return;*/
	world->worldMap[wallID_x][wallID_y] = 0;
	isPickingUp = 0;
	//delete this;
}

bool Key::getPicked()
{
	if (isPickingUp)
		this->open();
	return isPickingUp;
}

void draw(sf::RenderTarget& window)
{
	//		if (this != nullptr)
	//			window.draw(S_Key);
}