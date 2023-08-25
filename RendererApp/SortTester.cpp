#include "SortTester.h"
#include <memory>;
#include <vector>;

std::shared_ptr<std::vector<int>> SortTester::GetRandomInts(int count)
{
	std::shared_ptr<std::vector<int>> ptr = std::make_shared<std::vector<int>>(std::vector<int>(count, 0));
	for (int i = 0; i < count; i++)
	{
		(*ptr)[i] = rand() % 100;
	}
	return ptr;
}

std::shared_ptr<std::vector<int>> SortTester::CopyVector(std::shared_ptr<std::vector<int>> original)
{
	return std::shared_ptr<std::vector<int>>(original);
}
