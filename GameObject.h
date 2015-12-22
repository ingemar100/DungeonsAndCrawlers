#pragma once
#include <string>

class GameObject
{

public:
	GameObject();
	~GameObject();

	enum gameObjecten
		{
			WAPEN, ETEN, KLEDING
		};

	std::string naam() { return _naam; };
	int getStrength() { return _strength; };

	void setNaam(std::string naam) { _naam = naam; };
	void setStrength(int strength) { _strength = strength; };
	void setType(gameObjecten type) { soort = type; };
	gameObjecten getType() { return soort; };

private:
	std::string _naam = "";
	int _strength = 0;
	gameObjecten soort;


};

