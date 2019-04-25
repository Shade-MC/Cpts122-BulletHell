#include "downEnemy.h"

void downEnemy::generatePath( sf::Vector2f &position,  sf::Vector2f &resolution) {
	path = new sf::Vector2f[resolution.y +this->getSize().y +5];

	sf::Vector2f pos;
	pos.x = position.x;
	for (int i = 0; i < resolution.y + this->getSize().y + 5; ++i) {
		pos.y = i *3;
		path[i] = pos;
	}
}