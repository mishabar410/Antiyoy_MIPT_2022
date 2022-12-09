#include<iostream>
#include "Player.h"
#include "Cell.h"
#include "Entity.h"

Player::Player(Cell* start_cell) {
	money = 10;
	self_cells = [start_cell];
}