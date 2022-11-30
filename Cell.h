#pragma once
#include <SFML/Graphics.hpp>

class Cell
{
public:
	Cell(float x, float y, sf::RenderWindow* window);
	sf::RenderWindow* get_window();
	void render();
	
private:
	sf::Vector2f coord;
	sf::RenderWindow* window;
};

