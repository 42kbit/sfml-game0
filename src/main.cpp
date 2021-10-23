#include "SFML/Graphics.hpp"
#include "Global/Configuration.h"
#include "Entities/Player.h"

#include "Buffers/RenderBuffer.h"
#include "Buffers/UpdatableBuffer.h"
#include "Buffers/EventableBuffer.h"

#include "World/World.h"

#include <iostream>

int main()
{
    sf::Clock deltaTimer;

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::Event event;

    Configuration::m_Window = &window;
    Configuration::m_Event = &event;
    Configuration::m_World = new World();
    
    Player player(sf::Vector2f(window.getSize() / 2U), 10.f);

    window.setVerticalSyncEnabled(1);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            EventableBuffer::execute();
            if (event.type == sf::Event::Closed)
                window.close();
        }

        UpdatableBuffer::execute();

        window.clear();
        RenderBuffer::execute();
        window.display();

        Configuration::m_Dtclock.restart();
    }

    return 0;
}