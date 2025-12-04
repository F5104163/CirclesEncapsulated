
#include "Trail.h"
#include "Framework.h"

template class Trail<Vector2>;
template class Trail<float>;
template class Trail<int>;

template<typename T>
Trail<T>::Trail(int c)
{
	memoryCount = c;
	memory = std::vector<Vector2>();
}

template<typename T>
void Trail<T>::Draw()
{
	for (int i = 0; i < std::size(memory); i++)
	{
		DrawCircle(memory[i].X, memory[i].Y, 10);
	}
}

template<typename T>
void Trail<T>::Tick(Shape<T>* parent)
{
	memory.push_back(parent->GetPosition());
	if (std::size(memory) > memoryCount) memory.erase(memory.front());
}