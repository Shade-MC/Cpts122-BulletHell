#include "downEnemy.h"
#include <iostream>

void downEnemy::generatePath(sf::Vector2f &position, sf::Vector2f &resolution) {
	path = new sf::Vector2f[resolution.y];

	sf::Vector2f pos;
	pos.x = position.x;
	for (int i = 0; i < resolution.y ; ++i) {
		pos.y = i;
		std::cout <<pos.x << ","<< pos.y << std::endl;
	}
}