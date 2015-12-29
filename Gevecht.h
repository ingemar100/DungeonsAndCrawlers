#pragma once
#include <vector>
#include "Enemy.h"
#include "Ruimte.h"
#include "Held.h"
#include <iostream>
#include "Dialogue.h"

class Gevecht
{
public:
	Gevecht(Ruimte* r);
	~Gevecht();
	void start();
private:
	Ruimte* ruimte;
	void playTurn();
	bool fighting;
};

