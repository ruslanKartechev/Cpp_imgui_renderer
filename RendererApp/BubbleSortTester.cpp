#include <iostream>
#include <memory>;
#include <vector>
#include "BubbleSortTester.h"
#include "BubbleSort.h"
#include "SortAlgorithm.h"
#include "SortTesterResult.h"

std::shared_ptr<SortTesterResult> BubbleSortTester::RunTest()
{
	int numbers_count = 10;
	std::shared_ptr<std::vector<int>> randoms = GetRandomInts(numbers_count);
	std::shared_ptr<SortTesterResult> result = std::make_shared<SortTesterResult>();
	
	result->sort_name = "Bubble";
	result->additional_output = "no";
	result->unsorted = CopyVector(randoms);
	
	SortAlgorithm* sort = new BubbleSort();
	sort->Sort(randoms);
	result->number_of_steps = sort->GetNumberOfSteps();
	result->sorted = randoms;
	delete sort;
	return result;
}

void BubbleSortTester::ShowResult(std::shared_ptr<SortTesterResult> result)
{
	std::cout << "NAME: " << result->sort_name << std::endl;

	auto unsorted = *result->unsorted.get();
	std::cout << "Unsorted array" << std::endl;
	for (int val : unsorted)
	{
		std::cout << "No sort: " << val << std::endl;
	}
	auto sorted = *result->sorted.get();

	std::cout << "Sorted array" << std::endl;
	for (int val : sorted)
	{
		std::cout << "sorted: " << val << std::endl;
	}
}
