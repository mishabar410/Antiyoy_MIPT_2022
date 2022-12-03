#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
class Cell
{
public:
	Cell(float x, float y, sf::RenderWindow* window);
	sf::RenderWindow* get_window();
	void render();
	sf::Vector2f get_coord();
	std::optional<Entity*> entity_pointer; /*��������� �� �������� ������ ������*/

private:
	sf::Vector2f coord;/*координаты*/
	sf::RenderWindow* window;
	unsigned short int Player_status; /*���� 0 - ������, ����� �� ������ ������*/
};
