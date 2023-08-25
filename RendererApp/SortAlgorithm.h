#pragma once
#include <memory>
#include <vector>
class SortAlgorithm
{
public:
	virtual void Sort(std::shared_ptr<std::vector<int>> data) = 0;
	virtual int GetNumberOfSteps() { return m_numbere_of_steps; }

protected:
	bool m_numbere_of_steps;
};

