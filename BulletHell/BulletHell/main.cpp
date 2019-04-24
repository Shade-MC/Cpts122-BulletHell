//#include "PA9.h"
#include "downEnemy.h"	

int main()
{
	vector<Projectile *> Bullets;
	vector<Projectile *>::iterator iProjectile;

	vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

	sf::RenderWindow window(modes[0],"BulletHell",sf::Style::Fullscreen);
	sf::Vector2f resolution( modes[0].width,modes[0].height);
	
	sf::Texture texture;
	if (!texture.loadFromFile("Galaga_Fighter.png"))
		return EXIT_FAILURE;

	sf::Sprite player(texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(player);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			Projectile *nProj = new Projectile(5.f, sf::Color::White, *(new sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2)), true, *(new sf::Vector2f(0, .0001)));
			Bullets.push_back(nProj);
		}
		// Bullet Movement Loop
		for ( iProjectile = Bullets.begin(); iProjectile != Bullets.end(); ++iProjectile)
		{

			//gets the velocity of the given projectile and moves it
			(*iProjectile)->move((*iProjectile)->getVelocity());
			//if((*iProjectile)->ge)
		}
		 
	}

	return 0;
}