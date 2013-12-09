#ifndef SCENENODE_HPP
#define SCENENODE_HPP

#include "Category.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>
#include <set>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;
		typedef std::pair<SceneNode*, SceneNode*> Pair;


	public:
	    explicit          SceneNode(Category::Type category = Category::None);
								//SceneNode();

		void					attachChild(Ptr child);
		Ptr						detachChild(const SceneNode& node);

		void					update(sf::Time dt);

		sf::Vector2f			getWorldPosition() const;
		sf::Transform			getWorldTransform() const;

        void                 checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
        void                 checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);

        virtual unsigned int        getCategory() const;


		virtual sf::FloatRect getBoundingRect() const;
        virtual bool isMarkedForRemoval() const;
		virtual bool isDestroyed() const;


	private:
		virtual void		 updateCurrent(sf::Time dt);
		void				 updateChildren(sf::Time dt);

		virtual void	     draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void	     drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void			     drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

		void                 drawBoundingRect(sf::RenderTarget& target, sf::RenderStates) const;

	private:
		std::vector<Ptr>	 mChildren;
		SceneNode*			 mParent;
		Category::Type       mDefaultCategory;
};

bool        collision(const SceneNode& lhs, const SceneNode& rhs);
float       distance(const SceneNode& lhs, const SceneNode& rhs);

#endif // BOOK_SCENENODE_HPP
