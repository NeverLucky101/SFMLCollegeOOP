#include "SFML/include/SFML/Graphics.hpp"




int main() {

	//initialize game object

	sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing Mushroom");

	sf::Texture mushroomTexture;
	mushroomTexture.loadFromFile("deps/images/Mushroom.png");
	sf::Sprite mushroom(mushroomTexture);
	sf::Vector2u size = mushroomTexture.getSize();
	mushroom.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f incriment(0.1f, 0.1f);

	






	while (window.isOpen())
	{
		//Handle keyboard events
		sf::Event event;

		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}


		//Update game objects
		if((mushroom.getPosition().x + (size.x / 2) > window.getSize().x && incriment.x > 0) || (mushroom.getPosition().x - (size.x / 2) < 0 && incriment.x < 0))
		{
			//reverse direction on the x axis
			incriment.x = -incriment.x;
			mushroom.setColor(sf::Color::Red);
		}
		if((mushroom.getPosition().y + (size.y / 2) > window.getSize().y && incriment.y > 0) || (mushroom.getPosition().y - (size.y / 2) < 0 && incriment.y < 0))
		{
			//reverse direction in the y axis
			incriment.y = -incriment.y;
			mushroom.setColor(sf::Color::White);

		}

		mushroom.setPosition(mushroom.getPosition() + incriment);

		window.clear(sf::Color::Black);


		//Render game objects

		window.draw(mushroom);

		window.display();
	}

	return 0;
}