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
	void showStatus();
	void setWapenInGebruik(GameObject* wapen);
	void setKledingInGebruik(GameObject* kleding);
	void consumeer(GameObject* eten);
	int getAanval();
	int getVerdediging();
	int getOpmerkzaamheid();
	int getLevenspunten();
	bool hit(int enemyAanval);
	void setLevenspunten(int _levenspunten);

	void vlucht();
	void addErvaring(int punten);
	void showInventory();

	GameObject* getWapenInGebruik() { return wapenInGebruik; }
	GameObject* getKledingInGebruik() { return kledingInGebruik; }

private:
	static Held* instance;
	static bool instanceFlag;
	GameObject* wapenInGebruik = nullptr;
	GameObject* kledingInGebruik = nullptr;
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
	void removeFromInventory(GameObject* toRemove);
	void levelUp();
};

