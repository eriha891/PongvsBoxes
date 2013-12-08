#include "block.h"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>


Block::Block(Type type, const TextureHolder& textures)
: mType(type), mSprite(textures.get(Textures::Block))
{
    sf::FloatRect bounds = mSprite.getLocalBounds();
	 mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Block::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}
sf::FloatRect Block::getBoundingRect() const
{
        return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}
unsigned int Block::getCategory() const
{
      return Category::Block;
}

