#include "Eventable.h"
#include "../Buffers/EventableBuffer.h"
Eventable::Eventable()
{
	EventableBuffer::add_sub(this);
}

Eventable::~Eventable()
{
	EventableBuffer::delete_sub(this);
}
