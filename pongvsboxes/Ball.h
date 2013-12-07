#ifndef BALL_H
#define BALL_H


#include <String>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "ResourceIdentifier.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Ball : public Entity
{
public:
     Ball(const TextureHolder& textures);

     virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


protected:

    sf::Sprite mSprite;
};

#endif
