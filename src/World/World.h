#include "Tile.h"
#include "../Components/Renderable.h"

#include <cinttypes>

const uint32_t WORLD_SIZE_X = 16;
const uint32_t WORLD_SIZE_Y = 16;

class World : public Renderable 
{
public:
	World();
	~World();

private:
	virtual void on_render(sf::RenderTarget&) override;

	Tile** m_TileMap;
};