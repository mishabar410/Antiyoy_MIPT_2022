#pragma once
#include <SFML/Graphics.hpp>

class Cell
{
public:
	Cell(float x, float y, sf::RenderWindow* window) {
		Cell::Player_status = 0;
	};
	sf::RenderWindow* get_window();
	void render();
	Entity* entity_pointer; /*Указатель на существо вкутри клетки*/
	
private:
	sf::Vector2f coord;
	sf::RenderWindow* window;
	unsigned short int Player_status; /*Если 0 - пустая, далее по номеру игрока*/
};

