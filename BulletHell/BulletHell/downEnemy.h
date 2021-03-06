#pragma once

#include "Enemy.h"

class downEnemy : public Enemy {
public:
	downEnemy( sf::Vector2f &position,  sf::Vector2f & size,  sf::Vector2f &resolution, vector<Projectile *> &bullets) : Enemy(position, size,resolution, bullets) {
		setPosition(position);
		setFillColor(sf::Color::Red);
		generatePath(position, resolution);
	}
	
private:
	void generatePath( sf::Vector2f &position,  sf::Vector2f &resolution);
};