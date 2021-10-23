#pragma once

#include "Tile.h"
#include "../Components/Renderable.h"

#include <map>
#include <cinttypes>

const uint32_t WORLD_SIZE_X = 16;
const uint32_t WORLD_SIZE_Y = 16;

class World : public Renderable 
{
public:
	World();
	~World();

	Tile& getTileAt(int x, int y) { return m_TileMap[x][y]; };
	std::map<uint32_t, TileType>& getTileID() { return m_TileIDMap; };

private:
	virtual void on_render(sf::RenderTarget&) override;

	Tile** m_TileMap;

	std::map<uint32_t, TileType> m_TileIDMap;
};