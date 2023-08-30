#pragma once
#include <memory>;
#include <vector>;
#include "SortTesterResult.h"

class SortTester
{
public:
	virtual std::shared_ptr<SortTesterResult> RunTest() = 0;
	virtual void PrintResults(std::shared_ptr<SortTesterResult> result) = 0;
protected:
	std::shared_ptr<std::vector<int>> GetRandomInts(int count);
	std::shared_ptr<std::vector<int>> CopyVector(std::shared_ptr<std::vector<int>> original);
};

