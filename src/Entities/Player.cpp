#include "Player.h"
#include "../Global/Configuration.h"
#include <iostream>

Player::Player(sf::Vector2f pos, float radius) : Entity(pos), m_GFX(new sf::CircleShape)
{
	m_GFX->setRadius(radius);
	m_GFX->setOrigin(radius / 2.f, radius / 2.f);
}

Player::~Player()
{
	delete m_GFX;
}

void Player::on_update()
{
	m_Position += m_Velocity;

	m_GFX->setPosition(m_Position);
}

void Player::on_render(sf::RenderTarget& win)
{
	win.draw(*m_GFX);
}
