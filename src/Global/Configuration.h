#pragma once
#include "SFML/Graphics.hpp"

class Configuration{
public:
	static sf::RenderWindow* get_renderWin();

	static sf::Event* get_event();
	static sf::Int32 get_deltaTime();

	friend int main(void);
private:
	static sf::RenderWindow* window;
	static sf::Event* event;
	static sf::Clock dt_clock;
};