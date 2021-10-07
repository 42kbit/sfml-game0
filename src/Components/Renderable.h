#pragma once
namespace sf { class RenderTarget; };
class Renderable {
public:
	Renderable();
	~Renderable();

	virtual void on_render(sf::RenderTarget&) = 0;
private:
};