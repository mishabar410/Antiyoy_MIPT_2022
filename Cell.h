#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "Entity.h"

class Cell
{
public:
	Cell(float x, float y, sf::RenderWindow* window);
	sf::RenderWindow* get_window();
	void render();
	sf::Vector2f get_coord();
	std::optional<Entity*> entity_pointer; /*Pointer to entity in this cell*/

private:
	sf::Vector2f coord;/*координаты*/
	sf::RenderWindow* window;
	unsigned short int Player_status; /*0, if there no player, Player_num if there is*/
};
