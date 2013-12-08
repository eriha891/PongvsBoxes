#include "Ball.h"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>


Ball::Ball(Type type, const TextureHolder& textures)
: mType(type), mSprite(textures.get(Textures::Ball))
{

   sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Ball::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}
sf::FloatRect Ball::getBoundingRect() const
{
        return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}
unsigned int Ball::getCategory() const
{
      return Category::Ball;
}

