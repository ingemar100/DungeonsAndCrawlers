#pragma once

#include <vector>
#include "Spul.h"
#include "Val.h"
#include "Enemy.h"
#include <map>

class Val;
class GameObject;
class Ruimte
{
public:
	Ruimte();
	~Ruimte();
	void setFormaat(std::string _formaat) {
		formaat = _formaat;
	};
	std::string getFormaat() {
		return formaat;
	};
	void setOrdelijkheid(std::string _ordelijkheid) {
		ordelijkheid = _ordelijkheid;
	};
	std::string getOrdelijkheid() {
		return ordelijkheid;
	};
	void setMeubels(std::string _meubels) {
		meubels = _meubels;
	};
	std::string getMeubels() {
		return meubels;
	};
	void setVerlichting(std::string _verlichting) {
		verlichting = _verlichting;
	};
	std::string getVerlichting() {
		return verlichting;
	};
	void setOpbergruimte(std::string _opbergruimte) {
		opbergruimte = _opbergruimte;
	};
	std::string getOpbergruimte() {
		return opbergruimte;
	};
	void setVersiering(std::string _versiering) {
		versiering = _versiering;
	};
	std::string getVersiering() {
		return versiering;
	};
	void setTemperatuur(std::string _temperatuur) {
		temperatuur = _temperatuur;
	};
	std::string getTemperatuur() {
		return temperatuur;
	}

	std::string getBeschrijving();
	std::string getMapTile();

	void addGameObject(GameObject* gameObject);
	void removeObject();
	GameObject* search();
	GameObject* getGameObject() {
		return _gameObject;
	}
	bool hasGameObject() { return _gameObject != nullptr; }

	void addEnemy(Enemy* enemy);
	void destroyEnemy(Enemy* toRemove);
	std::vector<Enemy*>& getEnemies() {
		return _enemies;
	}
	bool hasEnemy() { return _enemies.size() > 0; }

	void addVal(Val* val);
	bool hasVal();
	void doVal();

	std::map<std::string, Ruimte*>& getAdjacentRooms() {
		return adjacentRooms;
	};

	bool heeftTrapOmhoog() {
		return trapOmhoog;
	}

	bool heeftTrapOmlaag() {
		return trapOmlaag;
	}

private:
	int xCoord;
	int yCoord;

	std::string formaat = "";
	std::string ordelijkheid = "";
	std::string meubels = "";
	std::string verlichting = "";
	std::string opbergruimte = "";
	std::string versiering = "";
	std::string temperatuur = "";
	std::map<std::string, Ruimte*> adjacentRooms;
	bool visited = false;
	bool trapOmhoog = false;
	bool trapOmlaag = false;
	bool eindbaas = false;

	GameObject* _gameObject = nullptr;
	std::vector<Enemy*> _enemies;
	Val* _val = nullptr;

	friend class Kerker;
	friend class Held;
	friend class Engine;
};

