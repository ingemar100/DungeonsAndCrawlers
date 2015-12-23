#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::use()
{
	if (soort == WAPEN) {
		Held::getInstance().setWapenInGebruik(this);
	}
	else if (soort == KLEDING) {
		Held::getInstance().setKledingInGebruik(this);
	}
	else if (soort == ETEN) {
		Held::getInstance().consumeer(this);
	}
}
