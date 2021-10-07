#pragma once
#include <vector>
template<typename T>
class Buffer
{
public:
	static void add_sub(T* sub);
	static void delete_sub(T* sub);

	static std::vector<T*>& get_subs();

	static void execute();
private:
	static std::vector<T*> subscribers;
};

template<typename T>
void erase_vec_element(std::vector<T*>& vec, T* element)
{
	auto itr = std::find(vec.begin(), vec.end(), element);
	if (itr != vec.cend()) {
		vec.erase(vec.begin() + std::distance(vec.begin(), itr));
	}
}