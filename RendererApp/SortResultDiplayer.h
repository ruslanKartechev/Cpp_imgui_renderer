#pragma once
#include "SortTesterResult.h"
#include <memory>
class SortResultDiplayer
{
public:
	virtual void Display(std::shared_ptr<SortTesterResult> result) = 0;
};

