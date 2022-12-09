#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Entity.h"

Cell::Cell(float x, float y, sf::RenderWindow* window)
{
    Cell::entity_pointer = std::nullopt;

    sf::CircleShape hexagon(25, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(25, 25);
    this->coord.x = x;
    this->coord.y = y;
    hexagon.setPosition(x, y);
    this->window = window;
    this->Player_status = 0;
}

Cell:Cell():
{

}

sf::RenderWindow* Cell::get_window()
{
    return this->window;
}

void Cell::render()
/*рисует шестиугольник aka клетку*/
{
    sf::CircleShape hexagon(25, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(25, 25);
    hexagon.setPosition(coord.x, coord.y);
    sf::RenderWindow* win = this->get_window();
    win->draw(hexagon);

}

sf::Vector2f Cell::get_coord()
{
    return coord;
}
