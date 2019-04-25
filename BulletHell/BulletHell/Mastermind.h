#pragma once
#include "downEnemy.h"

class Mastermind {
public:
	Mastermind(sf::RenderWindow &window, sf::Vector2f *playerPos);
	void addEnemy(Enemy * newEnemy);
	void updatePositions();
	void drawSuad();
private:
	sf::RenderWindow &window;
	vector<Enemy*> squad;
	sf::Vector2f *playerPos;
};
Enemy * createRandomEnemy(sf::Vector2f resolution, sf::Vector2f size, vector<Projectile *> &bullets);