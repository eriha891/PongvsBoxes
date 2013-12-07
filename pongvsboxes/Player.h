#ifndef PLAYER_H
#define PLAYER_H

#include <String>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
public:

    sf::RectangleShape _rect;
    sf::Vector2f pos;
    sf::Vector2f siz;
    //sf::RectangleShape _rect;

    //sf::Sprite _sprite;
    //sf::Image  _image;
    //std::string filename;

    //bool _isloaded;

    //float x, y;

    //float length, width, height;

    //sf::Vector2f speed;

    Player();
    void setPosition(float xpos, float ypos);
    void setSize(float w, float h);
    void setFillColor();
    //void Load(std::string filename);
    void draw(sf::RenderWindow &window);
    ~Player();
};

#endif
