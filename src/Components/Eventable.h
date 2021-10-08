#pragma once
#include <SFML/Graphics.hpp>
class Eventable {
public:
	Eventable();
	~Eventable();

	virtual void on_event_poll(sf::Event&) = 0;
};