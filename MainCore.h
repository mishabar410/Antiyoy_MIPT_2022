#pragma once
#include <vector>
#include "GameCore.h"
#include "Player.h"
#include "Cell.h"
#include "Entity.h"




class MainCore {

private:

public:
	MainCore();
	GameCore GraphicsCore;
	bool gamestatus;
	GameCore Core;
	Player Player1;
	Player Player2;
	Player* players; /*[Player1, Player2*/
	Cell Map[20][20];
	Cell* Map_pointer[20][20]; /*x, y coords*/
	std::vector<Entity*> Entities; /*Вектор всех существ в игре*/
	void entity_steps(Cell* StartCell);
};