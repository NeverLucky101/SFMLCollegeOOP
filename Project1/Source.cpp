#include "SFML/include/SFML/Graphics.hpp"


sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello, SFML", sf::Style::Default);


int main() {

	//initialize game object

	//rectangle
	sf::RectangleShape rect(sf::Vector2f(500,300));
	rect.setFillColor(sf::Color::White);
	rect.setPosition(viewSize.x / 2, viewSize.y / 2);
	rect.setOrigin(sf::Vector2f(rect.getSize().x/2, rect.getSize().y/2));

	//circle
	sf::CircleShape circ(100);
	circ.setFillColor(sf::Color::Red);
	circ.setPosition(viewSize.x / 2, viewSize.y / 2);
	circ.setOrigin(circ.getRadius(), circ.getRadius());

	//triangle
	sf::ConvexShape tri;
	tri.setPointCount(3);
	tri.setPoint(0,sf::Vector2f(-100,0));
	tri.setPoint(1, sf::Vector2f(0, -200));
	tri.setPoint(2, sf::Vector2f(100, 0));
	tri.setFillColor(sf::Color::Blue);
	tri.setPosition(viewSize.x / 2, viewSize.y / 2);







	while (window.isOpen())
	{
		//Handle keyboard events

		//Update game objects
		window.clear(sf::Color::Green);
		//Render game objects
		window.draw(rect);
		window.draw(circ);
		window.draw(tri);
		window.display();
	}

	return 0;
}