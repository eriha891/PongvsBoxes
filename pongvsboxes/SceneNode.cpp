#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Foreach.hpp"
#include "SceneNode.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>


SceneNode::SceneNode(Category::Type category)
: mChildren()
, mParent(nullptr)
, mDefaultCategory(category)
{

}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (Ptr& p) { return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time)
{
	// Do nothing by default
}

void SceneNode::updateChildren(sf::Time dt)
{
	FOREACH(Ptr& child, mChildren)
		child->update(dt);
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Apply transform of current node
	states.transform *= getTransform();

	// Draw node and children with changed transform
	drawCurrent(target, states);
	drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget&, sf::RenderStates) const
{
	// Do nothing by default
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	FOREACH(const Ptr& child, mChildren)
		child->draw(target, states);
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;

	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
		transform = node->getTransform() * transform;

	return transform;
}
sf::FloatRect SceneNode::getBoundingRect() const
{
        return sf::FloatRect();
}
void SceneNode::drawBoundingRect(sf::RenderTarget& target, sf::RenderStates) const
{
        sf::FloatRect rect = getBoundingRect();

        sf::RectangleShape shape;
        shape.setPosition(sf::Vector2f(rect.left, rect.top));
        shape.setSize(sf::Vector2f(rect.width, rect.height));
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineColor(sf::Color::Green);
        shape.setOutlineThickness(1.f);

        target.draw(shape);
}
bool SceneNode::isMarkedForRemoval() const
{
        // By default, remove node if entity is destroyed
        return isDestroyed();
}
bool SceneNode::isDestroyed() const
{
        // By default, scene node needn't be removed
        return false;
}
bool collision(const SceneNode& lhs, const SceneNode& rhs)
{
        return lhs.getBoundingRect().intersects(rhs.getBoundingRect());
}
void SceneNode::checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs)
{
        if (this != &node && collision(*this, node) && !isDestroyed() && !node.isDestroyed())
                collisionPairs.insert(std::minmax(this, &node));

        FOREACH(Ptr& child, mChildren)
                child->checkNodeCollision(node, collisionPairs);
}
void SceneNode::checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs)
{
        checkNodeCollision(sceneGraph, collisionPairs);

        FOREACH(Ptr& child, sceneGraph.mChildren)
                checkSceneCollision(*child, collisionPairs);
}
unsigned int SceneNode::getCategory() const
{
        return mDefaultCategory;
}
//float distance(const SceneNode& lhs, const SceneNode& rhs)
//{
//        return length(lhs.getWorldPosition() - rhs.getWorldPosition());
//}



