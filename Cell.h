#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Cell
{
public:
	Cell(float x, float y, sf::RenderWindow* window, float radius = 25, Entity* entity_pointer = 0);
	sf::RenderWindow* get_window();
	void render();
	sf::Vector2f get_coord();
	bool IsinCell(sf::Vector2i mouse_pos);
	Entity* entity_pointer;//may be use optional

private:
	sf::Vector2f coord;/*координаты*/
	sf::RenderWindow* window;
	unsigned short int Player_status; /*0, if there no player, Player_num if there is*/
	int radius;
};
