#include "MainCore.h"
#include "Player.h"
#include "Gamecore.h"
#include "Entity.h"
#include "Cell.h"


void MainCore::entity_steps(Cell* StartCell) {
    /*
    Сперва идет проверка на то, есть ли Entity в клетке, через Cell::entity_pointer. (Продумать
    как это сделать?)
    Используя Map в GameCore вернуть массив указателей на клетки в которые можно ходить
    Клетки в которых находятся Entity (у каждой клетки есть entity_pointer), должны 
    проверяться на power, и только в случае, если сила основного воина больше защищающегося
    передавать указатель на клетку.
    */
}

void Maincore::Maincore() {
    gamestatus = True;
    for (unsigned short int x = 0; x < 20; x++) {
        for (unsigned short int y = 0; y < 20, y++) {
            Map[x][y] = Cell(x, y);
            Map_pointer[x][y] = &Map[x][y];
        }
    }
    Player1 = Player(Map_pointer[20][20]);
    Player2 = Player(Map_pointer[0][0]);
    Core = GameCore(Map_pointer, Player1, Player2);

}