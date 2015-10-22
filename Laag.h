#pragma once
#include <vector>
#include "Ruimte.h"

class Laag
{
public:
	Laag();
	~Laag();
	void init();
	void setRuimtes(std::vector<std::vector<Ruimte*>> ruimtes);
	std::string getMap();
private:
	std::vector<std::vector<Ruimte*>> ruimtes;
};

