#pragma once

#include "Cell.h"
#include "Entity.h"

class Player {
private:

public:
	Player(Cell* start_cell);
	Player();
	unsigned short int money;
	Cell* self_cells;
	Cell* self_entity_cells; /*Cells, where there are entities*/
	bool movestatus; /*1 if Player's move now*/
};
