#pragma once
#include "iostream"
#include "SortTester.h"
#include "SortTesterResult.h"

class BubbleSortTester : public SortTester
{
public:
	std::shared_ptr<SortTesterResult> RunTest() override;
	void ShowResult(std::shared_ptr<SortTesterResult> result) override;
};

