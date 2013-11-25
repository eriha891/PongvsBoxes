#include <SFML/OpenGL.hpp>
#include <String>

class Player
{
public:
    Player();
    Player(GLfloat x, GLfloat y, GLfloat z, GLfloat length, GLfloat height, GLfloat width);

    ~Player();

    GLfloat* getVertexData();
    int getVertexSize();

    void setPosition(GLfloat xx, GLfloat yy, GLfloat zz);


private:
    std::string name;
    int numberOfLives;
    GLfloat x, y, z;
    GLfloat length, width, height;
    GLfloat* vertexArrayData;
};

