#pragma once
#include "SortAlgorithm.h"
#include <memory>

class BubbleSort : public SortAlgorithm
{
public :
	void Sort(std::shared_ptr<std::vector<int>> data) override;
	
};

