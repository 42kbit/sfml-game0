#include "World.h"
#include "../Global/Configuration.h"
#include <random>
World::World()
{
    m_TileIDMap.emplace(GRASS_ID, "res/textures/grass.png");
    m_TileIDMap.emplace(WALL_ID, "res/textures/stone.png");

    m_TileMap = new Tile*[WORLD_SIZE_X];
    for (uint32_t i = 0; i < WORLD_SIZE_X; i++)
    {
        m_TileMap[i] = new Tile[WORLD_SIZE_Y];
    }
    for(uint32_t i = 0; i < WORLD_SIZE_X; i++)
        for(uint32_t j = 0; j < WORLD_SIZE_Y; j++)
        {
            m_TileMap[i][j].setTileType( m_TileIDMap.find(rand()%4 == 0? WALL_ID:GRASS_ID)->second );

            m_TileMap[i][j].getGFX().setSize({
            Configuration::get_renderWin()->getSize().x * 1.0f / WORLD_SIZE_X, 
            Configuration::get_renderWin()->getSize().y * 1.0f / WORLD_SIZE_Y
            });
            m_TileMap[i][j].getGFX().setPosition(sf::Vector2f(
                i*(Configuration::get_renderWin()->getSize().x * 1.0f / WORLD_SIZE_X),
                j*(Configuration::get_renderWin()->getSize().y * 1.0f / WORLD_SIZE_Y)
                ));
        }
}

World::~World()
{
    for (uint32_t i = 0; i < WORLD_SIZE_X; i++)
        delete[] m_TileMap[i];
    delete[] m_TileMap;
 
}

void World::on_render(sf::RenderTarget& win)
{
    for(uint32_t i = 0; i < WORLD_SIZE_X; i++)
        for(uint32_t j = 0; j < WORLD_SIZE_Y; j++)
            win.draw(m_TileMap[i][j].getGFX());
}