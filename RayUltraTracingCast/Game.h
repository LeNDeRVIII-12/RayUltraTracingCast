#pragma once

class MiniMap;
class Player;
class Camera;
class World;
class Enemy;
class Key;

class Game
{
private:
	MiniMap* miniMap_;
	Player* player;
	Camera* camera;
	Enemy* enemy;
	Key* key;
public:
	Game();

	void run();
};
