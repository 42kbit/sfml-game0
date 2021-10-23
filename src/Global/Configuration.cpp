
#include "Configuration.h"

sf::RenderWindow* Configuration::m_Window = 0;
sf::Event* Configuration::m_Event = 0;
World* Configuration::m_World = 0;
sf::Clock Configuration::m_Dtclock;

World& Configuration::getWorld()
{
    return *m_World;
}

sf::RenderWindow* Configuration::get_renderWin()
{
    return m_Window;
}

sf::Event* Configuration::get_event()
{
    return m_Event;
}

sf::Int32 Configuration::get_deltaTime()
{
    return m_Dtclock.getElapsedTime().asMicroseconds();
}

