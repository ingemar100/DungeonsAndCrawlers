#pragma once
#include <vector>
#include "Laag.h"

class Kerker
{
public:
	Kerker();
	~Kerker();
private:
	std::vector<Laag> lagen;
	void slaOp();
	void laad();
};

