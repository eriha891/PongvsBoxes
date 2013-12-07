#ifndef PLAYER_H
#define PLAYER_H


#include <String>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "ResourceIdentifier.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Player : public Entity
{
public:
     Player(const TextureHolder& textures);

     virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


protected:

    sf::Sprite mSprite;
};

#endif
