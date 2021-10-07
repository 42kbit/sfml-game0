#include "Renderable.h"
#include "../Buffers/RenderBuffer.h"
Renderable::Renderable()
{
	RenderBuffer::add_sub(this);
}

Renderable::~Renderable()
{
	RenderBuffer::delete_sub(this);
}
