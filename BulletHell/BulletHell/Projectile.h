#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
//#include <vector>

using std::vector;


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