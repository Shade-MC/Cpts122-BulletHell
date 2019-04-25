#pragma once
#include "downEnemy.h"

class Mastermind {
public:
	Mastermind(sf::RenderWindow &window);
	void addEnemy(Enemy & newEnemy);
	void updatePositions();
	void drawSuad();
private:
	sf::RenderWindow &window;
	vector<Enemy&> squad;
};