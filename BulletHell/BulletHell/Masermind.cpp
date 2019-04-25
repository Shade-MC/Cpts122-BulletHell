#include "Mastermind.h"

Mastermind::Mastermind(sf::RenderWindow &window, sf::Sprite *player) : window(window), squad() {
	this->player = player;
}
void Mastermind::addEnemy(Enemy * newEnemy) {
	if (newEnemy != nullptr)
	{
		squad.push_back(newEnemy);
	}
}
void Mastermind::updatePositions() {


	for (int i = 0; i < (int)squad.size(); ++i) {
		if (!outOfBounds(*squad[i], window)) {
			(*squad[i]).updataPos();
			if (rand() % 60 == 0) {
				sf::Vector2f playerTarget;
				playerTarget.x =  player->getPosition().x -  squad[i]->getPosition().x;
				playerTarget.y =   player->getPosition().y- squad[i]->getPosition().y;
			 	double magnitude = sqrt(pow(player->getPosition().x ,2)+ pow(player->getPosition().y,2));
				playerTarget.x = (playerTarget.x / magnitude)*5;
				playerTarget.y = (playerTarget.y / magnitude)*5;
				(*squad[i]).fireProjectile(playerTarget);
			}

		}
		else {
			Enemy *pTemp = (squad[i]);
			squad.erase(squad.begin()+i);
			delete pTemp;
		}
	}
}
void Mastermind::drawSuad() {
	for (int i = 0; i < squad.size(); ++i) {
		window.draw(*squad[i]);
	}
}

void Mastermind::enemyShot(vector<Projectile *> &bullet, int *Score) {
	vector<Projectile *>::iterator iProjectile;

	for (int i = 0; i < (int)squad.size(); ++i) {
		for (iProjectile = bullet.begin(); iProjectile != bullet.end();++iProjectile) {
			if ((*iProjectile)->getFriendly()) {
				if (intersects(*squad[i], (**iProjectile))) {

					Enemy *pTemp = (squad[i]);
					squad.erase(squad.begin() + i);
					delete pTemp;
					*Score += 10;
					break;
				}
			}


		}

	}
}

Enemy * createRandomEnemy(sf::Vector2f resolution, sf::Vector2f size, vector<Projectile *> &bullets) {
	int type = rand() % 1+1;
	Enemy * temp = nullptr;
	sf::Vector2f position(rand() % (int) resolution.x, 0);

	switch (type)
	{
	case 1:
		temp = (new downEnemy(position, size, resolution,bullets));

		break;
	}
	return temp;
}