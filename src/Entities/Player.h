#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "../Components/Eventable.h"

class Player : public Entity, public Eventable 
{
public:
	Player(sf::Vector2f pos, float radius);
	~Player();

	sf::Vector2f& getVelocity() { return m_Velocity; };

	const float friction = 0.95f;

private:
	float m_Force = 0.1f;

	sf::Vector2f m_Velocity;

	sf::CircleShape* m_GFX;

	sf::Vector2f m_RelativePos;
	
	virtual void on_update() override;
	virtual void on_render(sf::RenderTarget&) override;
	virtual void on_event_poll(sf::Event&) override;
};