

#include "Mastermind.h"
#include <iostream>


int main()
{
	int Score = 0;
	vector<Projectile *> Bullets;
	vector<Projectile *>::iterator iProjectile;
	Projectile *pPTemp;
	int pDelay = 0, dBuffer=5;
	vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	//sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	

	sf::RenderWindow window(modes[1],"BulletHell",sf::Style::Fullscreen);
	sf::Vector2f resolution( modes[1].width,modes[1].height);
	
	sf::Texture texture;
	if (!texture.loadFromFile("Galaga_Fighter.png"))
		return EXIT_FAILURE;
	sf::Sprite player(texture);

	/*sf::RectangleShape player((*(new sf::Vector2f(window.getSize().x / 12,
		window.getSize().y / 10)), sf::Color::Red,
		*(new sf::Vector2f((window.getSize().x / 2), ((window.getSize().y) - (window.getSize().y / 12))))));*/

	Projectile *nProj = new Projectile(5.f, sf::Color::Yellow, *(new Vector2f(window.getSize().x / 2, window.getSize().y / 2)), true, *(new Vector2f(0, -10000)));
	Bullets.push_back(nProj);

	player.setPosition(window.getSize().x / 2, window.getSize().y / 10);
	player.setScale(.7, .7);
	window.setFramerateLimit(60);

	sf::Vector2f enemySize(player.getGlobalBounds().width,player.getGlobalBounds().height);
	Mastermind mastermind(window, &player);
	

	srand(time(NULL));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();
		mastermind.drawSuad();
		window.draw(player);
		for (iProjectile = Bullets.begin(); iProjectile != Bullets.end(); ++iProjectile)
		{
			window.draw(**iProjectile);
		}
		window.display();
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (player.getPosition().x > 0)
			{
				player.move(Vector2f(-10, 0.f));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{

			if (player.getPosition().x<(window.getSize().x-40))

			{
				player.move(Vector2f(10, 0.f));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (player.getPosition().y > 0)
			{
				player.move(Vector2f(0.f, -10));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{

			if (player.getPosition().y<(window.getSize().y-60))

			{
				player.move(Vector2f(0.f, 10));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& pDelay==dBuffer )
		{
			Projectile *nProj = new Projectile(2.f, sf::Color::Yellow, *(new Vector2f(player.getPosition().x+16, player.getPosition().y)), true, *(new Vector2f(0, -12)));
			Bullets.push_back(nProj);
			pDelay = 0;
		}
		// Bullet Movement Loop
		for ( iProjectile = Bullets.begin(); iProjectile != Bullets.end();)
		{
			//gets the velocity of the given projectile and moves it
			(*iProjectile)->move((*iProjectile)->getVelocity());
			if (!(*iProjectile)->getFriendly()) {
				if (intersects(player, (**iProjectile))) {
					window.close();
					std::cout << "You have died!" << std::endl;
					std::cout << "Your Score: " << Score << std::endl;
				}
			}

			if (outOfBounds(**iProjectile, window))
			{
				pPTemp = (*iProjectile);
				iProjectile = Bullets.erase(iProjectile);
				delete pPTemp;
			}else{
				++iProjectile;
			}
		}
		if (pDelay < dBuffer)
		{
			++pDelay;
		}
		//spawn enemies
		if (rand() % 50 == 0) 
		{
			mastermind.addEnemy(createRandomEnemy(resolution, enemySize, Bullets));
		}
		mastermind.updatePositions();
		mastermind.enemyShot(Bullets, &Score);

	}

	return 0;
}