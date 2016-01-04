#pragma once
#include <string>
class Val
{
public:
	Val();
	~Val();
	std::string naam() { return _naam; };
	int getStrength() { return _strength; };

	void setNaam(std::string naam) { _naam = naam; };
	void setStrength(int strength) { _strength = strength; };

private:
	std::string _naam = "";
	int _strength = 0;
};

