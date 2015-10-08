#pragma once
#include <vector>
#include "Tegenstander.h"

class Gevecht
{
public:
	Gevecht();
	~Gevecht();
private:
	std::vector<Tegenstander> tegenstanders;
};

