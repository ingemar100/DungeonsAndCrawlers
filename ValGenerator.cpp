#include "ValGenerator.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

ValGenerator::ValGenerator()
{
	const std::string textfile("Vallen.txt");
	std::ifstream input_file(textfile); // Dze constructie opent de file voor het lezen;
	std::string line;
	while (getline(input_file, line)) {
		std::string buffer;
		std::stringstream ss(line);

		std::vector<std::string>tokens;

		while (std::getline(ss, buffer, ',')) {
			tokens.push_back(buffer);
		}
		if (tokens.size() > 1) {
			vallen[tokens[0]] = std::stoi(tokens[1]);
		}
	}
}


ValGenerator::~ValGenerator()
{
	vallen.clear();
}

Val * ValGenerator::createVal()
{
	Val* val = new Val();
	int randIndex = rand() % 2;
	int counter = 0;
	if (randIndex == 0) {
		int randIndex = rand() % vallen.size();
		for each(auto kv in vallen) {
			if (counter == randIndex) {
				val->setNaam(kv.first);
				val->setStrength(kv.second);
			}
			counter++;
		}
	}
	else{
		delete val;
		val = nullptr;
	}
	return val;
}
