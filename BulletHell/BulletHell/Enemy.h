#pragma once

#include "Projectile.h"

class Enemy : public sf::RectangleShape {
public:
	Enemy(sf::Vector2f &position, sf::Vector2f & size, sf::Vector2f &resolution) : sf::RectangleShape(sf::Vector2f(size)) {
		this->pos = 0;
	}
	
	void updataPos() {
		this->move(path[pos++]);
	}


protected:
	virtual void generatePath(sf::Vector2f &position, sf::Vector2f &resolution) = 0;
	int pos;
	sf::Vector2f *path;
};