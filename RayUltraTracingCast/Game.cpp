#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MiniMap.h"
#include "Player.h"
#include "Camera.h"
#include "World.h"
#include "Enemy.h"
#include "Key.h"

Game::Game()
{
	key = new Key(1, 1, 0, 1, 0);
	Weapon* hand = new Weapon(Hand, 35);
	enemy = new Enemy(15, 12, -1, 0, 0, 0.66, 0, 0, hand, 0, 100);
	player = new Player(22, 12, -1, 0, 0, 0.66, 0, 0, hand, 0, enemy, key, 100);
	miniMap_ = new MiniMap(*player);
	camera = new Camera(*player);
	world = new World(player, camera);
}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(static_cast<unsigned int>(screenWidth), static_cast<unsigned int>(screenHeight)), "Raycaster");
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		player->pickUp();
		if (key != nullptr)
		{
			key->getPicked();
//			key->draw(window);
		}

		double deltaTime = clock.restart().asSeconds();
		player->update(deltaTime);
		player->giveDamage();

		window.clear();
		player->move(deltaTime);
		camera->castRays(window);
		player->draw(window);
		miniMap_->draw(window);
		window.display();
	}
}