
#include "Player.h"

//Default constructor
Player::Player()
{

}


//Destructor
Player::~Player()
{

}

/*
//Returns the Vertex Array Data
GLfloat* Player::getVertexData()
{
    float size = 10.f;


    GLfloat vertices[] =
    {
        // positions    // colors (r, g, b, a)
        -size, -size, -size,  0, 0, 1, 1,
        -size,  size, -size,  0, 0, 1, 1,
        -size, -size,  size,  0, 0, 1, 1,
        -size, -size,  size,  0, 0, 1, 1,
        -size,  size, -size,  0, 0, 1, 1,
        -size,  size,  size,  0, 0, 1, 1,

         size, -size, -size,  0, 1, 0, 1,
         size,  size, -size,  0, 1, 0, 1,
         size, -size,  size,  0, 1, 0, 1,
         size, -size,  size,  0, 1, 0, 1,
         size,  size, -size,  0, 1, 0, 1,
         size,  size,  size,  0, 1, 0, 1,

        -size, -size, -size,  1, 0, 0, 1,
         size, -size, -size,  1, 0, 0, 1,
        -size, -size,  size,  1, 0, 0, 1,
        -size, -size,  size,  1, 0, 0, 1,
         size, -size, -size,  1, 0, 0, 1,
         size, -size,  size,  1, 0, 0, 1,

        -size,  size, -size,  0, 1, 1, 1,
         size,  size, -size,  0, 1, 1, 1,
        -size,  size,  size,  0, 1, 1, 1,
        -size,  size,  size,  0, 1, 1, 1,
         size,  size, -size,  0, 1, 1, 1,
         size,  size,  size,  0, 1, 1, 1,

        -size, -size, -size,  1, 0, 1, 1,
         size, -size, -size,  1, 0, 1, 1,
        -size,  size, -size,  1, 0, 1, 1,
        -size,  size, -size,  1, 0, 1, 1,
         size, -size, -size,  1, 0, 1, 1,
         size,  size, -size,  1, 0, 1, 1,

        -size, -size,  size,  1, 1, 0, 1,
         size, -size,  size,  1, 1, 0, 1,
        -size,  size,  size,  1, 1, 0, 1,
        -size,  size,  size,  1, 1, 0, 1,
         size, -size,  size,  1, 1, 0, 1,
         size,  size,  size,  1, 1, 0, 1,
    };

    for (int i=0; i<getVertexSize(); i++)
    {
        vertexArrayData[i]=vertices[i];
    }

    return vertexArrayData;
}*/

/*
//Returns the size of the vertex array data
int Player::getVertexSize()
{
    return 252;
}*/


void Player::setPosition(float xx, float yy, float zz = -100.f)
{
    x = xx;
    y = yy;
    z = zz;
}
