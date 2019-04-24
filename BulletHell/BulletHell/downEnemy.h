#pragma once

#include "Enemy.h"

class downEnemy : public Enemy {
public:
	downEnemy(sf::Vector2f &position, sf::Vector2f & size, sf::Vector2f &resolution) : Enemy(position, size,resolution) {
		sf::RectangleShape::setPosition(position);
		generatePath(position, resolution);
	}
	
private:
	void generatePath(sf::Vector2f &position, sf::Vector2f &resolution);
};