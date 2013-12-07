#include "Ball.h"

Ball::Ball()
{
    pos.x = 1.0f;
    pos.y = 1.0f;
    vel.x = 1.0f;
    vel.y = 1.0f;
    speed = 1.0f;
}

Ball::Ball(float xpos, float ypos)
{
    pos.x = xpos;
    pos.y = ypos;
}

void Ball::setPosition(float xpos, float ypos)
{
    pos.x = xpos;
    pos.y = ypos;
}

void Ball::updatePosition(float xpos, float ypos)
{
    pos.x = xpos;
    pos.y = ypos;
}

void Ball::setVelocity(float xpos, float ypos)
{
    vel.x = xpos;
    vel.y = ypos;
}
