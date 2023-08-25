#pragma once
#include <iostream>;
#include <memory>;
#include <vector>
#include <string>

class SortTesterResult
{
public:
	std::shared_ptr<std::vector<int>> unsorted;
	std::shared_ptr<std::vector<int>> sorted;
	std::string sort_name;
	std::string additional_output;
	int number_of_steps = 0;
};

