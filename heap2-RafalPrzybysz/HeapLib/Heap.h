#pragma once
#include <vector>
#include <iomanip>

template<typename KeyType, typename ValueType>
class Heap
{
public:
	using KeyValueType = std::pair<KeyType, ValueType>;
private:
	std::vector<KeyValueType> table;

	size_t parentIndex(size_t index) const noexcept
	{
		return (index - 1) / 2;
	}

	size_t leftChildIndex(size_t index) const noexcept
	{
		return index * 2 + 1;
	}

	size_t rightChildIndex(size_t index) const noexcept
	{
		return index * 2 + 2;
	}

	size_t getLargestFromParentAndHisChildren(size_t parent)
	{
		//TODO zaimplementowaæ metodê zwracaj¹c¹ indeks wêz³a i najwiêkszej wartoœci z trójki wez³ów: rodzic i jego dzieci
		// tu warunki spawdzajace maks z 3 elementow.
	/*	if(table[parent]>table[parent+1] && table[parent]> table[parent+2])
			return parent;

		if (table[parent+1] > table[parent+2])
			return parent+1 ;

		if (table[parent+2] > table[parent+1])
			return parent+2;*/

		auto largest = parent;

		auto leftChild = leftChildIndex(parent);

		if (leftChild < table.size() && table[leftChild]> table[largest])
			largest = leftChild;

		auto rightChild = rightChildIndex(parent);

		if (rightChild < table.size() && table[rightChild]> table[largest])
			largest = rightChild;

		return largest;
	}

	void heapify(size_t index)
	{
		//TODO zaimplemetowaæ metodê heapify
		auto largest = getLargestFromParentAndHisChildren(index);

		/*auto leftChild = leftChildIndex(index);

		if (leftChild < table.size() && table[leftChild]> table[largest])
			largest = leftChild;

		auto rightChild = rightChildIndex(index);

		if (rightChild < table.size() && table[rightChild]> table[largest])
			largest = rightChild;*/
		
		if (largest != index)
		std::swap(index, largest);

		heapify(largest);

	}

	template<typename StreamType>
	void print(StreamType& stream, size_t index, int indent, std::string prefix) const
	{
		if (index < table.size())
		{
			if (indent > 0)
				stream << std::setw(indent) << " ";
			stream << prefix;
			stream << "[" << table[index].first << ", " << table[index].second << "]" << std::endl;
			print(stream, leftChildIndex(index), indent + 4, "L: ");
			print(stream, rightChildIndex(index), indent + 4, "R: ");
		}
	}
public:
	Heap()
	{
	}

	Heap(std::vector<KeyValueType> keyValues) : table(keyValues)
	{
		// TODO zbudowaæ kopiec w tablicy korzystaj¹c z metody heapify
		for (int i = 0; i < table.size(); ++i)
		{
			heapify(table.size());
		}
	}

	bool empty() const noexcept
	{
		return table.empty();
	}

	size_t size() const noexcept
	{
		return table.size();
	}

	template<typename StreamType>
	void print(StreamType& stream) const
	{
		print(stream, 0, 0, "");
	}

	std::vector<KeyValueType> const& getVector() const
	{
		return table;
	}
};

template<typename KeyType, typename ValueType>
std::ostream& operator <<(std::ostream& stream, Heap<KeyType, ValueType> const& heap)
{
	heap.print<std::ostream>(stream);
	return stream;
}
