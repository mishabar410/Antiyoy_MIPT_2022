#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Entity.h"

Cell::Cell(float x, float y, sf::RenderWindow* window, Entity* entity_ptr, float r)
{
    sf::CircleShape hexagon(radius, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(radius, radius);
    coord.x = x;
    coord.y = y;
    this->window = window;
    this->Player_status = 0;
    radius = r;
    entity_pointer = entity_ptr;
}

sf::RenderWindow* Cell::get_window()
{
    return window;
}

void Cell::render()
/*рисует шестиугольник aka клетку*/
{
    sf::CircleShape hexagon(radius, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::Green);
    //hexagon.setOrigin((float)radius, (float)radius);
    hexagon.setPosition(coord.x - radius, coord.y - radius);

    sf::RenderWindow* win = this->get_window();
    win->draw(hexagon);

}

sf::Vector2f Cell::get_coord()
{
    return coord;
}

bool Cell::IsinCell(sf::Vector2i point)
/*проблема с типами кое-как решилась.
* сам метод не работает как надо
* нужно добавить проверку на остальные 4 стороны
*/
{
    sf::Vector2f delta = this->get_coord();
    float x = point.x - delta.x;
    float y = point.y - delta.y;
    float distsq = x * x + y * y;
    if (distsq > radius * radius) return false;
    if (4 * distsq <= 3 * radius * radius) return true;
    return false;

}
