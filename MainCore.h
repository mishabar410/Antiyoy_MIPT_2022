#pragma once
#include <vector>
#include "Entity.h"

class MainCore {

private:
	Cell* Map[20][20]; /*������ ������, ������� ������������ �� ���� �����*/
	vector <Entity*> Entities; /*������ ���� ������� � ����*/
public:
	MainCore() {
		/*���������� ������� Map � Players*/
	}
};