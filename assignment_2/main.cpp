#include <SFML/Graphics.hpp>	
#include <iostream>
int main()
{
	const int mWidth = 800;
	const int mHeight = 720;
	sf::RenderWindow window(sf::VideoMode(mWidth, mHeight), "SFML works!");
	window.setFramerateLimit(60);
	int r = 0;
	int g = 255;
	int b = 225;
	sf::CircleShape circle(50);
	circle.setFillColor(sf::Color(r, g, b));
	circle.setPosition(300.0f, 300.0f);
	float circleMoveSpeed = 1.0f;
	sf::Font myFont;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		circle.move(circleMoveSpeed, 0.0f);	
		
		window.clear();

		
		window.draw(circle);
		// If you created a text object for your font, draw it here too

		// 3. Display everything you've drawn
		window.display();
	}

	return 0;
}
	
