#include "stdafx.h"
#include "GameDialog.h"
#include <iostream>
#include "Room.h"

GameDialog::GameDialog()
{
}


GameDialog::~GameDialog()
{
}

void GameDialog::setFightOptions(Room* room) {
	options.clear();
	options.push_back("hit");
	options.push_back("stab");
	options.push_back("move");
}

void GameDialog::setOptions(Room* room, bool isExit) {
	//Als de kamer vijanden heeft andere dialoog
	options.clear();

	if (room->hasEnemy()) {
		options.push_back("fight");
	}

	options.push_back("move");
	options.push_back("inventory");
	options.push_back("search");
	options.push_back("use");
	options.push_back("info");
	options.push_back("rest");
	options.push_back("drink");
	options.push_back("map");

	if (isExit) {
		options.push_back("exit");
	}
}

std::string GameDialog::fightDisplay(Room* room) {
	std::cout << "What do you want to do?" << std::endl;
	std::string optionString = "";
	for each (std::string option in options)
	{
		optionString += option + " | ";
	}
	std::cout << optionString;
	std::cout << std::endl;
	std::string chosenOption = "";
	std::getline(std::cin, chosenOption);
	return chosenOption;
}

std::string GameDialog::display(Room* room) {
	room->print();
	std::cout << "What do you want to do?" << std::endl;
	std::string optionString = "";
	for each (std::string option in options)
	{
		optionString += option + " | ";
	}
	std::cout << optionString;
	std::cout << std::endl;
	std::string chosenOption = "";
	std::getline(std::cin,  chosenOption);
	return chosenOption;
}



