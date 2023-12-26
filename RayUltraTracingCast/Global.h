#include <SFML/Graphics.hpp>
#include <cmath>
#include <chrono>
#include <iostream>
#include "Weapon.h"
#include "Entity.h"
#include "Object2D.h"
#include "Key.h"
#include "Enemy.h"
#include "Player.h"
#include "MiniMap.h"
#include "Camera.h"
#include "World.h"
#include "Game.h"
#define screenWidth 950
#define screenHeight 950
#define mapWidth 24
#define mapHeight 24
#define texWidth 64
#define texHeight 64

class World;
extern World* world;