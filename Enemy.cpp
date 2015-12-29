#include "Enemy.h"
#include <string>
#include <map>
#include <iostream>
#include "Held.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}


bool Enemy::hit(int heldAanval)
{
	this->verdediging;
	int r = rand() % 100;
	if (r < verdediging) {
		//ontweken
		std::cout << name << " heeft de aanval ontweken!\n";
	}
	else {
		levenspunten -= heldAanval;
		std::cout << "Je doet " << heldAanval << " schade aan de " << name << ". ";
		if (checkAlive()) {
			std::cout << "Hij heeft nog " << levenspunten << " levenspunten over \n";
		}
		else {
			std::cout << name << " is dood!\n";
		}
	}
	return checkAlive();
}

bool Enemy::checkAlive()
{
	if (levenspunten <= 0) {
		return false;
	}
	return true;
}

void Enemy::setName(std::string _name)
{
	name = _name;
}

void Enemy::setLevel(int _level)
{
	level = _level;
}

void Enemy::setLevenspunten(int _levenspunten)
{
	levenspunten = _levenspunten;
}

void Enemy::setVerdediging(int _verdediging)
{
	verdediging = _verdediging;
}

void Enemy::setAanval(int _aanval)
{
	aanval = _aanval;
}

void Enemy::doeActie()
{

	std::cout << "\n" + name + " valt " + Held::getInstance().getNaam() + " aan\n";
	Held::getInstance().hit(aanval);
}
