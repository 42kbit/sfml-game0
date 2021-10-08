#include "Buffer.h"
#include "../Components/Updatable.h"
#include "../Components/Renderable.h"
#include "../Components/Eventable.h"

#include "../Global/Configuration.h"

template class Buffer<Updatable>;
template class Buffer<Renderable>;
template class Buffer<Eventable>;

template<typename T>
std::vector<T*> Buffer<T>::subscribers;

template<typename T>
void Buffer<T>::add_sub(T* sub)
{
	subscribers.push_back(sub);
}

template<typename T>
void Buffer<T>::delete_sub(T* sub)
{
	auto itr = std::find(subscribers.begin(), subscribers.end(), sub);
	if (itr != subscribers.cend()) {
		subscribers.erase(subscribers.begin() + std::distance(subscribers.begin(), itr));
	}
	else
	{
		throw std::runtime_error("no such element");
	}
}

template<typename T>
inline std::vector<T*>& Buffer<T>::get_subs()
{
	return subscribers;
}

template<>
void Buffer<Updatable>::execute()
{
	for (unsigned int i = 0; i < subscribers.size(); i++)
	{
		subscribers[i]->on_update();
	}
}

template<>
void Buffer<Renderable>::execute()
{
	for (unsigned int i = 0; i < subscribers.size(); i++)
	{
		subscribers[i]->on_render(*Configuration::get_renderWin());
	}
}

template<>
void Buffer<Eventable>::execute()
{
	for (unsigned int i = 0; i < subscribers.size(); i++)
	{
		subscribers[i]->on_event_poll(*Configuration::get_event());
	}
}
