#pragma once
#include <string>
#include <vector>
#include "spul.h"
#include "Ruimte.h"

class GameObject;
class Held
{
public:
	bool isAlive();
	std::string getNaam();
	void setNaam(std::string _naam);
	static Held& getInstance();
	void moveTo(Ruimte* _ruimte);
	Ruimte* getRuimte();
	static void deleteInstance();
	void addToInventory(GameObject* _gameObject);
	std::vector<GameObject*> getInventory();

private:
	static Held* instance;
	static bool instanceFlag;
	Held();
	~Held();
	std::vector<GameObject*> inventory;
	std::string naam;
	int level;
	int levenspunten;
	int ervaringspunten;
	int aanval;
	int verdediging;
	int opmerkzaamheid;
	Ruimte* ruimte;

	//Held instance;
};

