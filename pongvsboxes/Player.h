#include <String>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    ~Player();

    void setPosition(float xx, float yy, float zz);

    void setSpeed(sf::Vector2f theSpeed);


private:
    float x, y;

    float length, width, height;

    sf::Vector2f speed;
};

