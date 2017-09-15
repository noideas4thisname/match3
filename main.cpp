#include <SFML/Graphics.hpp>

#include "gem_manager.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(740,480), "Match-3");
	window.setFramerateLimit(60);
	
	sf::Texture texBackground;
	texBackground.loadFromFile("images/background.png");

	sf::Sprite background(texBackground);

	GemManager gemManager(15, 15);
	gemManager.reset();

	while(window.isOpen()) {
		sf::Event e;
		while(window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();

			if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Escape) window.close();
			
			if (e.type == sf::Event::MouseButtonPressed) {
				if (e.mouseButton.button == sf::Mouse::Left) {
					gemManager.click(sf::Mouse::getPosition(window));
				}
			}
		}

		window.draw(background);
		gemManager.draw(window);
		window.display();
	}
		
	return 0;
}