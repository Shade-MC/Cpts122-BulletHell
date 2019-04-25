#pragma once
#include <iostream>

#include "Projectile.h"

class Enemy : public sf::RectangleShape {
public:
	Enemy(sf::Vector2f &position, sf::Vector2f & size, sf::Vector2f &resolution, vector<Projectile *> &bullets) : sf::RectangleShape(size) , bullets(bullets){
		this->pos = 0;
	}

	void updataPos() {
		setPosition(path[pos++]);

	}


protected:
	virtual void generatePath(sf::Vector2f &position, sf::Vector2f &resolution) = 0;
	int pos;
	sf::Vector2f *path;
	vector<Projectile *> & bullets;
};