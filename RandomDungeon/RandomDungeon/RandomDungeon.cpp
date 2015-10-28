// RandomDungeon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Layer.h"
#include "StartDialog.h"
#include "GameDialog.h"
#include "Player.h"
#include <iostream>
#include <string>
#include "Room.h"

StartDialog dialog;
GameDialog inGame;
Room* currentRoom = nullptr;
bool playing = true;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::string playerName = dialog.activate();

	Player* player = new Player();
	player->setName(playerName);

	int size = dialog.setSize();

	Layer* l = new Layer(size);

	while (playing) {
		currentRoom = l->getCurrentRoom(player);
		inGame.setOptions();
		std::string action = inGame.display(currentRoom);
		if (action.find("move") == 0) {
			if (l->canMove(action, player)) {
				playing = player->executeAction(action);
			}
			else {
				std::cout << "You cannot move this way" << std::endl;
			}
		}
		else {
			playing = player->executeAction(action);
		}

	}

	delete l;
	delete player;
    return 0;
}

