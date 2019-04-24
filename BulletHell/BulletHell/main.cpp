
//#include "PA9.h"
#include "downEnemy.h"	
#include <iostream>

#include "PA9.h"
	

int main()
{
	vector<Projectile *> Bullets;
	vector<Projectile *>::iterator iProjectile;
	Projectile *pPTemp;

	vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	//sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	

	sf::RenderWindow window(modes[0],"BulletHell",sf::Style::Fullscreen);
	sf::Vector2f resolution( modes[0].width,modes[0].height);
	
	sf::Texture texture;
	if (!texture.loadFromFile("Galaga_Fighter.png"))
		return EXIT_FAILURE;
	sf::Sprite player(texture);

	/*sf::RectangleShape player((*(new sf::Vector2f(window.getSize().x / 12,
		window.getSize().y / 10)), sf::Color::Red,
		*(new sf::Vector2f((window.getSize().x / 2), ((window.getSize().y) - (window.getSize().y / 12))))));*/

	player.setPosition(window.getSize().x / 2, window.getSize().y / 10);
	player.setScale(.7, .7);
	window.setFramerateLimit(60);

	sf::Vector2f enemyPos(window.getSize().x / 2, window.getSize().y);
	sf::Vector2f enemySize(window.getSize().x / 50, window.getSize().y / 50);
	downEnemy test(enemyPos, enemySize, resolution);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (player.getPosition().x > 0)
			{
				player.move(Vector2f(-20, 0.f));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (player.getPosition().x<(window.getSize().x - player.getLocalBounds().width))
			{
				player.move(Vector2f(20, 0.f));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (player.getPosition().y > 0)
			{
				player.move(Vector2f(0.f, -20));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (player.getPosition().y<(window.getSize().y- player.getLocalBounds().height))
			{
				player.move(Vector2f(0.f, 20));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			Projectile *nProj = new Projectile(5.f, sf::Color::White, *(new Vector2f(window.getSize().x / 2, window.getSize().y / 2)), true, *(new Vector2f(0, .0001)));
			Bullets.push_back(nProj);
		}

		// Bullet Movement Loop
		for ( iProjectile = Bullets.begin(); iProjectile != Bullets.end(); ++iProjectile)
		{

			//gets the velocity of the given projectile and moves it
			(*iProjectile)->move((*iProjectile)->getVelocity());
			window.draw(**iProjectile);
			if (outOfBounds(**iProjectile, window))
			{
				pPTemp = (*iProjectile);
				Bullets.erase(iProjectile);
				delete pPTemp;
			}
		}
		
		test.updataPos();
		window.clear();
		window.draw(test);
		window.draw(player);
		window.display();
	}

	return 0;
}