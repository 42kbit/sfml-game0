#include "SFML/Graphics.hpp"
#include "Entity.h"

class Player : public Entity 
{
public:
	Player(sf::Vector2f pos, float radius);
	~Player();

	sf::Vector2f& getVelocity() { return m_Velocity; };

private:
	sf::Vector2f m_Velocity;
	sf::CircleShape* m_GFX;
	
	virtual void on_update() override;
	virtual void on_render(sf::RenderTarget&) override;
};