#include "Player.h"
#include "../Global/Configuration.h"
#include "../World/World.h"
#include <iostream>

Player::Player(sf::Vector2f pos, float radius) : Entity(pos), m_GFX(new sf::CircleShape)
{
	m_GFX->setFillColor(sf::Color::Red);
	m_GFX->setRadius(radius);
	m_GFX->setOrigin(radius / 2.f, radius / 2.f);
	m_GFX->setOutlineThickness(1.f);
	m_GFX->setOutlineColor(sf::Color::Yellow);
}

Player::~Player()
{
	delete m_GFX;
}

void Player::on_update()
{
	auto nextPos = m_Position + m_Velocity;
	if (nextPos.x < 0 || nextPos.x > Configuration::get_renderWin()->getSize().x)
		m_Velocity = sf::Vector2f(-m_Velocity.x, m_Velocity.y);
	if (nextPos.y < 0 || nextPos.y > Configuration::get_renderWin()->getSize().y)
		m_Velocity = sf::Vector2f(m_Velocity.x, -m_Velocity.y);

	auto& worldRef = Configuration::getWorld();
    float cellSize = 800.f / 16.f;
	nextPos = m_Position + m_Velocity;
	auto& tileRef = worldRef.getTileAt((m_Position.x + m_Velocity.x) / cellSize, (m_Position.y + m_Velocity.y) / cellSize);
    if(tileRef.getTileType() == worldRef.getTileID().find(1)->second)
	{
		auto& ballBound = m_GFX->getGlobalBounds();
		auto& wallBound = tileRef.getGFX().getGlobalBounds();
		if(ballBound.top > wallBound.top || ballBound.top + ballBound.height < wallBound.top + wallBound.height)
			m_Velocity = sf::Vector2f(m_Velocity.x, -m_Velocity.y);
		if(ballBound.left > wallBound.left || ballBound.left + ballBound.width < wallBound.left + wallBound.width)
			m_Velocity = sf::Vector2f(-m_Velocity.x, m_Velocity.y);
	}

	m_Position += m_Velocity;
	m_Velocity *= friction;

	m_GFX->setPosition(m_Position);
}

void Player::on_event_poll(sf::Event& ev)
{
	if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
	{
		m_RelativePos = sf::Vector2f(sf::Mouse::getPosition(*Configuration::get_renderWin()));
	}

	if (ev.type == sf::Event::MouseButtonReleased && ev.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2f unNormalizedDir = -(sf::Vector2f(sf::Mouse::getPosition(*Configuration::get_renderWin())) - m_RelativePos);

		m_Velocity += unNormalizedDir * m_Force;
	}
}

void Player::on_render(sf::RenderTarget& win)
{
	win.draw(*m_GFX);
}
