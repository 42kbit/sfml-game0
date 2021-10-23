#pragma once
#include "SFML/Graphics.hpp"

#include "../World/World.h"

class Configuration{
public:
	static sf::RenderWindow* get_renderWin();

	static sf::Event* get_event();
	static sf::Int32 get_deltaTime();

	static World& getWorld();

	friend int main(void);
private:
	static World* m_World;

	static sf::RenderWindow* m_Window;
	static sf::Event* m_Event;
	static sf::Clock m_Dtclock;
};