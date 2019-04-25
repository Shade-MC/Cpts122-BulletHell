#pragma once
#include <SFML/Graphics.hpp>
#include "PA9.h"

class Projectile : public sf::CircleShape
{
public:
	Projectile(float radius, const sf::Color &c, sf::Vector2f &pos, bool team, sf::Vector2f &nVelo) : sf::CircleShape(radius)
	{
		this->setFillColor(c);
		this->setPosition(pos);
		friendly = team;
		velocity = nVelo;

	}
	sf::Vector2f &getVelocity();
protected: 
	bool friendly;
	sf::Vector2f velocity;
	//true friendly/player projectile
	//false enemy projectile
};

bool intersects(sf::Shape &shape, Projectile &proj);
bool intersects(sf::Sprite &sprite, Projectile &proj);