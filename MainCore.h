#pragma once
#include <vector>
#include "Entity.h"

class MainCore {

private:
	Cell* Map[20][20]; /*Массив клеток, которые представляют из себя карту*/
	vector <Entity*> Entities; /*Вектор всех существ в игре*/
public:
	MainCore() {
		/*Необходимо создать Map и Players*/
	}
};