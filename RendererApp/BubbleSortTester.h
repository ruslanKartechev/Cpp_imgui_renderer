#pragma once
#include "iostream"
#include "SortTester.h"
#include "SortTesterResult.h"

class BubbleSortTester : public SortTester
{
public:
	std::shared_ptr<SortTesterResult> RunTest() override;
	void PrintResults(std::shared_ptr<SortTesterResult> result) override;
};

