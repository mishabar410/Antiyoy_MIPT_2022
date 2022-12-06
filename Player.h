#pragma once

#include "Cell.h"
#include "Entity.h"

class Player {
private:

public:
	unsigned short int money;
	Cell* self_cells;
	Cell* self_entity_cells; /*Cells, where there are entities*/
};