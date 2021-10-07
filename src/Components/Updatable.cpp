#include "Updatable.h"
#include "../Buffers/UpdatableBuffer.h"
Updatable::Updatable()
{
	UpdatableBuffer::add_sub(this);
}

Updatable::~Updatable()
{
	UpdatableBuffer::delete_sub(this);
}
