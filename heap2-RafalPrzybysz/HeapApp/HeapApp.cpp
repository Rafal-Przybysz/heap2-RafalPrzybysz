#include <iostream>
#include <vector>
#include "../HeapLib/Heap.h"

int main()
{
	size_t size;
	do
	{
		std::cout << "Enter size:";
		std::cin >> size;
		if (size > 0)
		{
			std::vector<Heap<int, int>::KeyValueType> v;
			for (size_t i = 1; i <= size; ++i)
				v.push_back({ i, i });
			Heap<int, int> heap( v );
			std::cout << heap;
		}
	} while (size > 0);
}
