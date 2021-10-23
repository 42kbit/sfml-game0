#pragma once
#include "SFML/Graphics.hpp"

#define GRASS_ID 0
#define WALL_ID 1

class TileType
{
public:
	TileType(sf::String path)
	{
		m_Texture = new sf::Texture();
		m_Texture->loadFromFile(path);
	} 

	~TileType()
	{
		delete m_Texture;
	}

	bool operator == (const TileType& other) const {return this->m_Texture == other.m_Texture;}; 

	const sf::Texture& getTexture() { return *m_Texture; };
private:
	sf::Texture* m_Texture;
};

class Tile 
{
public:
	sf::RectangleShape& getGFX() { return m_GFX; };
	const TileType& getTileType() { return *m_TileType; };
	void setTileType(TileType& type)
	{
		 m_TileType = &type;
		 m_GFX.setTexture(&m_TileType->getTexture());
	};

private:
	TileType* m_TileType;
	sf::RectangleShape m_GFX;
	// Pattern flyweight is not applied to m_GFX, cuz sfml doest support batching :(
};