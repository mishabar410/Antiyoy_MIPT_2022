#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Cell.h"
#include <vector>

Player::Player(Cell* start_cell) {
	money = 10;
	self_cells{ start_cell };
}