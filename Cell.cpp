#include "Cell.h"

Cell::Cell(float x, float y, sf::RenderWindow* window)
{
    sf::CircleShape hexagon(25, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(25, 25);
    this->coord.x = x;
    this->coord.y = y;
    hexagon.setPosition(x, y);
    this->window = window;
}

sf::RenderWindow* Cell::get_window()
{
    return this->window;
}

void Cell::render()
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
