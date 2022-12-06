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