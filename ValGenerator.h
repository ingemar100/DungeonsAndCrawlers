#pragma once
#include "Val.h"
#include <map>

class ValGenerator
{
	std::map<std::string, int> vallen;

public:
	ValGenerator();
	~ValGenerator();

	Val* createVal();
};

