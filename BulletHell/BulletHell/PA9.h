#pragma once

//#include <downEnemy.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.h";
using std::vector;
using sf::Vector2f;

bool outOfBounds(sf::Shape &shape, sf::Window &windo);
bool intersects(sf::Shape &shape, Projectile &proj);
bool intersects(sf::Sprite &sprite, Projectile &proj);