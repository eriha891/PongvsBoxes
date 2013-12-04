
#include "Player.h"

//Default constructor
Player::Player()
{

}


//Destructor
Player::~Player()
{

}

void Player::setPosition(float xx, float yy, float zz = -100.f)
{
    x = xx;
    y = yy;
}

void Player::setSpeed(sf::Vector2f theSpeed)
{
    speed = theSpeed;
}
