#include <SFML/Graphics.hpp>
#include "Round.h"
#include <iostream>


int main(int argc, char *argv[])
{

	// Create a new Game Round
	Round* round = new Round();

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

	std::cout << "Testar att skriva ut test!" << std::endl;
    //En ny kommentar
	//En kommentar
}
