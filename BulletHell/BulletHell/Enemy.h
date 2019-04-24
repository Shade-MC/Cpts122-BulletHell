#pragma once

#include "Projectile.h"

class Enemy : public sf::RectangleShape {
public:
	Enemy(sf::Vector2f &position, sf::Vector2f & size, sf::Vector2f &resolution) : sf::RectangleShape(sf::Vector2f(size)) {
		this->pos = 0;
	}
	virtual void generatePath() = 0;
	void updataPos() {
		this->move(path[pos++]);
	}


protected:
	int pos;
	sf::Vector2f *path;
};