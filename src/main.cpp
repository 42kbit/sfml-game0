#include "SFML/Graphics.hpp"
#include "Global/Configuration.h"
#include "Entities/Player.h"

#include "Buffers/RenderBuffer.h"
#include "Buffers/UpdatableBuffer.h"
#include "Buffers/EventableBuffer.h"

#include <iostream>

int main()
{
    sf::Clock deltaTimer;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::Event event;

    Configuration::window = &window;
    Configuration::event = &event;

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

        Configuration::dt_clock.restart();
    }

    return 0;
}