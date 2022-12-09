#include "MainCore.h"
#include "Player.h"
#include "Gamecore.h"
#include "Entity.h"
#include "Cell.h"


void MainCore::entity_steps(Cell* StartCell) {
    /*
    ������ ���� �������� �� ��, ���� �� Entity � ������, ����� Cell::entity_pointer. (���������
    ��� ��� �������?)
    ��������� Map � GameCore ������� ������ ���������� �� ������ � ������� ����� ������
    ������ � ������� ��������� Entity (� ������ ������ ���� entity_pointer), ������ 
    ����������� �� power, � ������ � ������, ���� ���� ��������� ����� ������ �������������
    ���������� ��������� �� ������.
    */
}

MainCore::MainCore() {
    bool gamestatus = 1;
    GameCore GraphicsCore = GameCore();
    for (unsigned short int x = 0; x < 20; x++) {
        for (unsigned short int y = 0; y < 20; y++) {
            Map[x][y] = Cell(x, y, GraphicsCore.window);
            Map_pointer[x][y] = &Map[x][y];
        }
    }
    Player1 = Player(Map_pointer[20][20]);
    Player2 = Player(Map_pointer[0][0]);

}