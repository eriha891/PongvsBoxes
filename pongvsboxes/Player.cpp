#include <SFML/OpenGL.hpp>
#include "Player.h"

//Default constructor
Player::Player()
{
    vertexArrayData = new GLfloat[getVertexSize()];
}

//Constructor
Player::Player(GLfloat xx, GLfloat yy, GLfloat zz=-100.f, GLfloat theLength = 50.f, GLfloat theHeight = 50.f, GLfloat theWidth = 10.f)
: x(xx), y(yy), z(zz), length(theLength), height(theHeight), width(theWidth)
{
    vertexArrayData = new GLfloat[getVertexSize()];
}

//Destructor
Player::~Player()
{
    delete vertexArrayData;
}

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
}


//Returns the size of the vertex array data
int Player::getVertexSize()
{
    return 252;
}


void Player::setPosition(GLfloat xx, GLfloat yy, GLfloat zz = -100.f)
{
    x = xx;
    y = yy;
    z = zz;
}
