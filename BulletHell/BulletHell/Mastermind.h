#pragma once
#include "downEnemy.h"

class Mastermind {
public:
	Mastermind(sf::RenderWindow &window, sf::Sprite *player);
	void addEnemy(Enemy * newEnemy);
	void enemyShot(vector<Projectile *> &bullet);
	void updatePositions();
	void drawSuad();
private:
	sf::RenderWindow &window;
	vector<Enemy*> squad;
	sf::Sprite *player;
};
Enemy * createRandomEnemy(sf::Vector2f resolution, sf::Vector2f size, vector<Projectile *> &bullets);