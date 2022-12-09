#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#include "Cell.h"
#include "Entity.h"

class GameCore {

	void update(int elapsed);/*elapsed �����, ����� �������� ���� �������, 
	� �� �������.������ ��������, ��� �� �����������*/
	void draw();

public:
	GameCore();
	void start();
	~GameCore();
	sf::RenderWindow* window;/*��������� �� ����*/

};

