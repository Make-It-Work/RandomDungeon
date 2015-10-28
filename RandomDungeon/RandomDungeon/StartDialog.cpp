#include "stdafx.h"
#include "StartDialog.h"
#include <iostream>


StartDialog::StartDialog()
{
}


StartDialog::~StartDialog()
{
}

std::string StartDialog::activate() {
	std::string playerName;
	std::cout << "Welcome to the dungeon, explorer. What is your name?" << std::endl;
	std::cin >> playerName;
	return playerName;
}

int StartDialog::setSize() {
	int size;
	std::cout << "How big do you want your adventure to be? Pick a number between 1 and 10" << std::endl;
	std::cin >> size;
	while (size < 1 || size > 10) {
		std::cout << "How big do you want your adventure to be? Pick a number between 1 and 10" << std::endl;
		std::cin >> size;
	}
	std::cout << "Good luck..." << std::endl;
	return size;
}
