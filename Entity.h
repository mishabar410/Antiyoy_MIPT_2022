#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"

class Entity
{
	sf::Texture tex;
	unsigned short int money_cost;
	unsigned short int power;
	unsigned short int coords;
public:
	Entity(std::string name, unsigned short x; unsigned short y);
	void render();
	sf::Sprite sprite;
	unsigned short int power;
	bool alive_status; /*if alive = 1, else 0*/
};

