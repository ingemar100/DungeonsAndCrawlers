#include "Enemy.h"
#include <string>
#include <map>
#include <iostream>

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

int Enemy::attack()
{
	std::cout << "Je bent aangevallen door je tegenstander, je verlies" << aanval << " van je levenspunten \n";
	return aanval;
}

bool Enemy::hit(int heldAanval)
{
	levenspunten -= heldAanval;
	if (checkAlive()) {
		std::cout << "Je hebt je tegenstander geraakt, maar hij heeft nog steeds " << levenspunten << " levenspunten over \n";
		return true;
	}
	else {
		std::cout << name << " is dood!\n";
		return false;
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
