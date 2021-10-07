
#include "Configuration.h"

sf::RenderWindow* Configuration::window = 0;
sf::Event* Configuration::event = 0;
sf::Clock Configuration::dt_clock;

sf::RenderWindow* Configuration::get_renderWin()
{
    return window;
}

sf::Event* Configuration::get_event()
{
    return event;
}

double Configuration::get_deltaTime()
{
    return dt_clock.getElapsedTime().asMilliseconds();
}

