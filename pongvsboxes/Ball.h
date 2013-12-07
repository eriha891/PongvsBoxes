#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Ball
{
public:

    sf::Vector2f pos;
    sf::Vector2f vel;
    float speed;

//Constructors
	Ball();

    Ball(float xpos, float ypos);

	void setPosition(float xpos, float ypos);
	void updatePosition(float xpos, float ypos);
    void setVelocity(float xpos, float ypos);

    ~Ball();
};
