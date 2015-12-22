#include "RoomGenerator.h"
#include "Ruimte.h"

RoomGenerator::RoomGenerator()
{
	const std::string textfile{ "roomAttributes.txt" };
	std::ifstream input_file{ textfile }; // stack-based file object; deze constructie opent de file voor lezen
	std::string line;
	int counter = 0;

	// getline() leest een regel die eindigt in een \n
	// (je kunt ook een 3e param meegeven als je een ander 'regeleinde' wil gebruiken)
	while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
		std::string property = keys[counter];
		std::istringstream buf(line);
		std::istream_iterator <std::string> beg(buf), end;
		std::vector<std::string> line(beg, end);
		properties[property] = line;
		counter++;
	}
	gog = new GameObjectGenerator();
}


RoomGenerator::~RoomGenerator()
{
}


Ruimte* RoomGenerator::createRoom() {
	Ruimte* room = new Ruimte();
	try {
		int RandIndex = rand() % properties["formaat"].size();
		room->setFormaat(properties["formaat"][RandIndex]);

		RandIndex = rand() % properties["ordelijkheid"].size();
		room->setOrdelijkheid(properties["ordelijkheid"][RandIndex]);

		RandIndex = rand() % properties["meubels"].size();
		room->setMeubels(properties["meubels"][RandIndex]);

		RandIndex = rand() % properties["verlichting"].size();
		room->setVerlichting(properties["verlichting"][RandIndex]);

		RandIndex = rand() % properties["opbergruimte"].size();
		room->setOpbergruimte(properties["opbergruimte"][RandIndex]);

		RandIndex = rand() % properties["versiering"].size();
		room->setVersiering(properties["versiering"][RandIndex]);
		
		RandIndex = rand() % properties["temperatuur"].size();
		room->setTemperatuur(properties["temperatuur"][RandIndex]);

		room->addGameObject(gog->createGameObject());
	}
	catch (...) {
		std::cout << "Invalid room properties";
	}
	return room;
}