#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
class Cell
{
public:
	Cell(float x, float y, sf::RenderWindow* window) {
		Cell::Player_status = 0;
		Cell::entity_pointer = std::nullopt
	};
	sf::RenderWindow* get_window();
	void render();
	std::optional<Entity*> entity_pointer; /*��������� �� �������� ������ ������*/

private:
	sf::Vector2f coord;
	sf::RenderWindow* window;
	unsigned short int Player_status; /*���� 0 - ������, ����� �� ������ ������*/
};
