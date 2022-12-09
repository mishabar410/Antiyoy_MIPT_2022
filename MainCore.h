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
	bool gamestatus;
	GameCore Core;
	Player Player1;
	Player Player2;
	Player* players; /*[Player1, Player2*/
	Cell Map[20][20];
	Cell* Map_pointer[20][20]; /*x, y coords*/
	std::vector<Entity*> Entities; /*������ ���� ������� � ����*/
	void entity_steps(Cell* StartCell);
	std::vector<std::vector<int>> adjacency_list(400, std::vector<int>());
};
