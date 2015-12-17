#pragma once

#include <vector>
#include "Spul.h"
#include "Val.h"
#include <map>

class Ruimte
{
public:
	Ruimte();
	~Ruimte();

	std::string getBeschrijving();
	std::string getMapTile();
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
	};
private:
	std::string formaat = "";
	std::string ordelijkheid = "";
	std::string meubels = "";
	std::string verlichting = "";
	std::string opbergruimte = "";
	std::string versiering = "";
	std::string temperatuur = "";
	Val val;
	std::vector<Spul> spullen;
};

