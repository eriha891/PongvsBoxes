#include "Player.h"

//Default constructor
Player::Player()
{
    pos.x = 500.0f;
    pos.y = 500.0f;
    siz.x = 100.0f;
    siz.y = 50.0f;
    _rect.setFillColor(sf::Color::Blue);
}

void Player::setPosition(float xpos, float ypos)
{
    pos.x = xpos;
    pos.y = ypos;
    _rect.setPosition(pos.x, pos.y);
}

void Player::setSize(float w, float h)
{
    siz.x = w;
    siz.y = h;
    _rect.setSize(siz);
}

void Player::setFillColor()
{
    _rect.setFillColor(sf::Color::Blue);
}

void Player::draw(sf::RenderWindow & renderWindow)
{
    renderWindow.draw(_rect);
}

//void Player::Setposition(float x, float y)
//{
//    _rect.setPosition(x,y);
//    _rect.setSize(sf::Vector2f(150.f,25.f));
//    _rect.setFillColor(sf::Color::Green);
//}

//Destructor
Player::~Player()
{

}
