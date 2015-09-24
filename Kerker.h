#pragma once
#include <vector>

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

