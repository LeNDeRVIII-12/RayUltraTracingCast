#pragma once
#include <SFML/Graphics.hpp>

class IDrawable
{
public:
	virtual ~IDrawable() {};
	virtual void draw(sf::RenderTarget& window) = 0;
};