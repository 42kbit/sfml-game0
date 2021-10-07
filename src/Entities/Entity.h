#include "SFML/Graphics.hpp"

#include "../Components/Updatable.h"
#include "../Components/Renderable.h"

class Entity : public Updatable, public Renderable
{
public:
	Entity() : m_Position({ 0,0 }) {}
	Entity(sf::Vector2f pos) : m_Position(pos) {}

	sf::Vector2f& getPosition() { return m_Position; };
protected:
	sf::Vector2f m_Position;
};