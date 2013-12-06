#include <SFML/Graphics.hpp>
#include "Player.h"

//Default constructor
Player::Player()
{

}


//Destructor
Player::~Player()
{

}
void Player::Draw(sf::RenderWindow & renderWindow)
{
    renderWindow.draw(_rect);
}

//void Player::Setposition(float x, float y)
//{
//    _rect.setPosition(x,y);
//    _rect.setSize(sf::Vector2f(150.f,25.f));
//    _rect.setFillColor(sf::Color::Green);
//}

void Player::setSpeed(sf::Vector2f theSpeed)
{
    speed = theSpeed;
}
