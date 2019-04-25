#include "Mastermind.h"

Mastermind::Mastermind(sf::RenderWindow &window) : window(window), squad() {
	
}
void Mastermind::addEnemy(Enemy & newEnemy) {
	squad.push_back(newEnemy);
}
void Mastermind::updatePositions() {
	for (int i = 0; i < squad.size(); ++i) {
		if (!outOfBounds(squad[i], window)) {
			squad[i].updataPos();
		}
		else {
			Enemy *pTemp = &(squad[i]);
			squad.erase(squad.begin()+i);
			delete pTemp;
		}
	}
}
void Mastermind::drawSuad() {
	for (int i = 0; i < squad.size(); ++i) {
		window.draw(squad[i]);
	}
}

Enemy & createRandomEnemy(sf::Vector2f resolution, sf::Vector2f size) {
	int type = rand() % 1;
	Enemy * temp;
	sf::Vector2f position(rand() % (int) resolution.x, 0);

	switch (type)
	{
	case 1:
		temp = new downEnemy(position, size, resolution);

		break;
	}
	return *temp;
}