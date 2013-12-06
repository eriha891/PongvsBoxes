#ifndef PLAYER_H
#define PLAYER_H


#include <String>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Player : public RectangleShape
{
public:
     Player();
     ~Player();

     void Load(std::string filename);
     void Draw(sf::RenderWindow &window);

//     void Setposition(float x, float y);

     void setSpeed(sf::Vector2f theSpeed);


private:


    sf::RectangleShape _rect;

    sf::Sprite _sprite;
    sf::Image  _image;
    std::string filename;

    bool _isloaded;

    float _x, _y;

    float length, width, height;

    sf::Vector2f speed;
};

#endif
