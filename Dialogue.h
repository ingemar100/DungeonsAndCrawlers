#pragma once
#include <string>
#include <vector>
#include <iostream>

class Dialogue
{
private:
	std::string description;
	std::vector<std::string> choices;

public:
	int activate()
	{
		std::cout << "\n" << description << std::endl;

		// Output and number the choices
		for (int i = 0; i < this->choices.size(); ++i){
			std::cout << i + 1 << ": " << this->choices[i] << std::endl;
		}

		// Repeatedly read input from stdin until a valid option is
		// chosen
		int userInput = -1;
		while (true)
		{
			std::cin >> userInput;
			if (userInput >= 0 && userInput <= this->choices.size())
			{
				return userInput;
			}
		}
	}

	// Dialogue my_dialogue("Hello", {"Choice1", "Choice"});
	Dialogue(std::string description, std::vector<std::string> choices)
	{
		this->description = description;
		this->choices = choices;
	}

	void addChoice(std::string choice)
	{
		this->choices.push_back(choice);
	}

	unsigned int size()
	{
		return this->choices.size();
	}
};