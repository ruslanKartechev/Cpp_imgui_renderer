#include "BubbleSort.h"
#include <vector>
#include <iostream>

void BubbleSort::Sort(std::shared_ptr<std::vector<int>> data)
{
	m_numbere_of_steps = 0;
	bool swapped = false;
	std::vector<int>* arr = data.get();
	int size = arr->size();
	for (int i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (int k = 0; k < size - i - 1; k++)
		{
			if ((*arr)[k] > (*arr)[k + 1])
			{

				int temp = (*arr)[k];
				(*arr)[k] = (*arr)[k + 1];
				(*arr)[k + 1] = temp;
				swapped = true;
				m_numbere_of_steps++;
			}
		}
		if (swapped == false)
			break;
	}
}
