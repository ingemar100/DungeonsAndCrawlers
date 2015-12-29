#pragma once
#include <string>
#include <map>

class Enemy
{
protected:
	int level = 0;
	int levenspunten = 0;
	int verdediging = 0;
	int aanval = 0;
	std::string name = "";

public:
	bool hit(int heldAanval);
	bool checkAlive();
	std::string getName() { return name; }
	int getAanval() { return aanval; }
	int getLevenspunten() { return levenspunten; }
	void setName(std::string _name);
	void setLevel(int _level);
	void setLevenspunten(int _levenspunten);
	void setVerdediging(int _verdediging);
	void setAanval(int _aanval);
	void doeActie();
	
	Enemy();
	~Enemy();
};

