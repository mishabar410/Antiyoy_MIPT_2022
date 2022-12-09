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

MainCore::MainCore() {
    gamestatus = 1;
    GraphicsCore = GameCore();
    /*for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++) {
            Map[x][y] = Cell(x, y, GraphicsCore.window);
            Map_pointer[x][y] = &Map[x][y];
        }
    }
    */
    Cell kk = Cell(1, 1, GraphicsCore.window);
    std::cout << kk.map_coord[0];
    /*Player1 = Player(&Map[20][20]);
    Player2 = Player(&Map[0][0]);*/

}