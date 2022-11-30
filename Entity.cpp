#include "Entity.h"

Entity::Entity(std::string name) {
	tex.loadFromFile(name);
	sprite.setTexture(tex);

}

void Entity::render()
{
	Cell* cell = this->cell;
	sf::RenderWindow* win = cell->get_window();
	win->draw(sprite);
}
