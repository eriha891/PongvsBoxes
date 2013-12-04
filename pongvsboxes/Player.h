#include <String>


class Player
{
public:
    Player();
    //Player(GLfloat x, GLfloat y, GLfloat z, GLfloat length, GLfloat height, GLfloat width);

    ~Player();

    //GLfloat* getVertexData();
    int getVertexSize();

    void setPosition(float xx, float yy, float zz);


private:
    float x, y, z;

    std::string name;
    int numberOfLives;
    float length, width, height;
    //GLfloat* vertexArrayData;
};

