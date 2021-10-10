#include "SFML/Graphics.hpp"

class Tile 
{
public:

	sf::RectangleShape& getGFX() { return m_GFX; };

private:
	sf::RectangleShape m_GFX;
	sf::Texture m_Texture;
};