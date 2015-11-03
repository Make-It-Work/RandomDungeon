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
#include <ctime>

StartDialog dialog;
GameDialog inGame;
Room* currentRoom = nullptr;
bool playing = true;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand(time(NULL));
	std::string playerName = dialog.activate();

	Player* player = new Player();
	player->setName(playerName);

	int size = dialog.setSize();

	Layer* l = new Layer(size);

	while (playing) {
		currentRoom = l->getCurrentRoom(player);
		inGame.setOptions(currentRoom, player->talisman.use(currentRoom, l->getStartRoom())==0);
		std::string action = inGame.display(currentRoom);
		if (action != "") {
			if (action.find("move") == 0) {
				if (l->canMove(action, player)) {
					playing = player->executeAction(action);
				}
				else {
					std::cout << "You cannot move this way" << std::endl;
				}
			} else if (action == "map") {
				l->draw();
			}
			else if (action == "exit") {
				playing = player->exit(currentRoom, l->getStartRoom());
			}
			else {
				if (action == "talisman") {
					int distance = player->talisman.use(currentRoom, l->getStartRoom());
					std::cout << "The talisman lights up and whispers the exit is " << distance << " rooms away." << std::endl;
				}
				else if (action == "grenade") {
					player->grenade.use(l, player);
				}
				else if (action == "compass") {
					std::cout << player->compass.use(l, player) << std::endl;
				}
				else if (action.find("search") == 0) {
					GameObject* go = currentRoom->search();
					if (go != nullptr) {
						currentRoom->removeObject();
						player->addToBackpack(go);
					}
				}
				else if(action.find("fight") == 0) {
					bool won = false;
					while (!won) {
						inGame.setFightOptions(currentRoom);
						std::string action = inGame.fightDisplay(currentRoom);

						if (action == "hit") {
							if (!currentRoom->getEnemy()->hit()) {
								won = true;
								currentRoom->destroyEnemy();
							}
						}
						else if (action == "stab") {
							GameObject* weapon = player->getWeapon();
							if (weapon != nullptr) {
								if (currentRoom->getEnemy()->stabbed(weapon->getStrength() + player->getStrength())) {
									won = true;
									currentRoom->destroyEnemy();
								}
							}
							else {
								std::cout << "You don't have a weapon to fight with. Use the use command to equip yourself with a weapon." << std::endl;
							}
						}
						if (currentRoom->hasEnemy()) {
							player->getAttacked(currentRoom->getEnemy()->attack());
						}
						currentRoom->doTrap();
						if (player->getHealth() <= 0) {
							playing = false;
							won = true;
						}
					}
				}
				playing = player->executeAction(action);
				if (playing) {
					if (currentRoom->hasEnemy()) {
						player->getAttacked(currentRoom->getEnemy()->attack());
					}
					currentRoom->doTrap();
				}
			}
		}
		if (player->getHealth() <= 0) {
			playing = false;
		}
	}

	delete l;
	delete player;
    return 0;
}

