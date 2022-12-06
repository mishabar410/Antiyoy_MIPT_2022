#pragma once
#include <vector>
#include "Entity.h"
#include "MainCore.cpp"

class MainCore {

private:

public:
	MainCore();
	bool gamestatus;
	GameCore Core;
	Player Player1;
	Player Player2;
	Player* players = [&Player1, &Player2];
	Cell Map[20][20];
	Cell* Map_pointer[20][20]; /*x, y coords*/
	vector <Entity*> Entities; /*������ ���� ������� � ����*/
};