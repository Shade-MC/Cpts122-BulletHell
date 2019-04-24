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