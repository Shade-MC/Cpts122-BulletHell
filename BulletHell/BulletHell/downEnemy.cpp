#include "downEnemy.h"


void downEnemy::generatePath(sf::Vector2f &position, sf::Vector2f &resolution) {
	path = new sf::Vector2f[resolution.y * 10];

	sf::Vector2f pos;
	pos.x = position.x;
	for (int i = 0; i < resolution.y * 10; ++i) {
		pos.y = i / 10.0f;

	}
}