#pragma once

#include "Projectile.h"

class Enemy : public sf::RectangleShape {
public:
	Enemy(sf::Vector2f &pos, sf::Vector2f & size) : sf::RectangleShape(sf::Vector2f(size)) {

	}
	virtual void generatePath() = 0;
	void move();


protected:
	int pos;
	sf::Vector2f path[];
};