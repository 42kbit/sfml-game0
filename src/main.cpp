#include "SFML/Graphics.hpp"
#include "Global/Configuration.h"

#include <iostream>

int main()
{
    sf::Clock deltaTimer;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::Event event;

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Configuration::window = &window;
    Configuration::event = &event;

    window.setVerticalSyncEnabled(1);

    while (window.isOpen())
    {
        std::cout << "DeltaTime: " << Configuration::get_deltaTime() << std::endl;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Configuration::dt_clock.restart();

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}