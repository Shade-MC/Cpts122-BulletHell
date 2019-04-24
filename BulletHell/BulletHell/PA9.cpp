#include "PA9.h"



bool outOfBounds(sf::Shape &shape, sf::Window &windo)
{
	bool OoB =false;
	float xWin = windo.getSize().x, yWin = windo.getSize().y,
		xShape = shape.getPosition().x, yShape = shape.getPosition().y;

	if (xShape > xWin || xShape < 0) 
	{
		OoB = true;
	}

	if (yShape > yWin || yShape < 0)
	{
		OoB = true;
	}
	return OoB;
}

bool intersects(sf::Shape &shape, Projectile &proj)
{
	bool intersect;
	float xS1 = 0, xS2 = 0, yS1 = 0, yS2 = 0;
	xS1 = shape.getPosition().x;
	xS2 = shape.getGlobalBounds().width + xS1;
	yS1 = shape.getPosition().y;
	yS2 = yS1 - shape.getGlobalBounds().height;
	float xP1 = 0, xP2 = 0, yP1 = 0, yP2 = 0;
	xP1 = proj.getPosition().x;
	xP2 = proj.getGlobalBounds().width + xP1;
	yP1 = proj.getPosition().y;
	yP2 = yP1 - proj.getGlobalBounds().height;


	if (xP1 >= xS1 || xP1 <= xS2)
	{
		intersect = true;
	}
	else if (xP2 >= xS1 || xP2 <= xS2)
	{
		intersect = true;

	}
	else if (yP1 >= yS1 || yP1 <= yS2)
	{
		intersect = true;

	}
	else if (yP2 >= yS1 || yP2 <= yS2)
	{
		intersect = true;

	}

	return intersect;

}
bool intersects(sf::Sprite &sprite, Projectile &proj)
{
	bool intersect;
	float xS1=0, xS2=0, yS1=0, yS2=0;
	xS1 = sprite.getPosition().x;
	xS2=sprite.getGlobalBounds().width+xS1;
	yS1 = sprite.getPosition().y;
	yS2 = yS1-sprite.getGlobalBounds().height;
	float xP1 = 0, xP2 = 0, yP1 = 0, yP2 = 0;
	xP1 = proj.getPosition().x;
	xP2 = proj.getGlobalBounds().width + xP1;
	yP1 = proj.getPosition().y;
	yP2 = yP1 - proj.getGlobalBounds().height;

	
	if (xP1 >= xS1 || xP1 <= xS2)
	{
		intersect = true;
	}
	else if (xP2 >= xS1 || xP2 <= xS2)
	{
		intersect = true;

	}
	else if (yP1 >= yS1 || yP1 <= yS2)
	{
		intersect = true;

	}
	else if (yP2 >= yS1 || yP2 <= yS2)
	{
		intersect = true;

	}

	return intersect;
}