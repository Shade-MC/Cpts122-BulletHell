
#include <SFML/Graphics.hpp>
#include <vector>


int main()
{
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

	sf::RenderWindow window(modes[0],"BulletHell",sf::Style::Fullscreen);
	int resHeight = modes[0].height, resWidth = modes[0].width;

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
	}

	return 0;
}