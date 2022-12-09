#include "MainCore.h"
#include "Player.h"
#include "Gamecore.h"
#include "Entity.h"
#include "Cell.h"


void MainCore::entity_steps(Cell* StartCell) {
    int x = StartCell->coord.x;
    int y = StartCell->coord.y;
    int coord = x * 20 + y;

    /*
    ������ ���� �������� �� ��, ���� �� Entity � ������, ����� Cell::entity_pointer. (���������
    ��� ��� �������?)
    ��������� Map � GameCore ������� ������ ���������� �� ������ � ������� ����� ������
    ������ � ������� ��������� Entity (� ������ ������ ���� entity_pointer), ������
    ����������� �� power, � ������ � ������, ���� ���� ��������� ����� ������ �������������
    ���������� ��������� �� ������.
    */
}

MainCore::Fill_adj_list() {
    for (unsigned int i = 0; i < 20; i++)
    {
        for (unsigned int j = 0; j < 20; j++)
        {
            if (i == 0 && j == 0)
            {
                adjacency_list[i * 20 + j].push_back(1);
                adjacency_list[i * 20 + j].push_back(20);
            }
            if (i == 19 && j == 0)
            {
                adjacency_list[i * 20 + j].push_back((i - 1) * 20);
                adjacency_list[i * 20 + j].push_back(i * 20 + 1);
            }
            if (i == 0 && j == 19)
            {
                adjacency_list[i * 20 + j].push_back(18);
                adjacency_list[i * 20 + j].push_back(38);
                adjacency_list[i * 20 + j].push_back(39);
            }
            if (i == 19 && j == 19)
            {
                adjacency_list[i * 20 + j].push_back(i * 20 + j - 1);
                adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j);
            }
            if (i == 0 && (j > 0 && j < 19))
            {
                adjacency_list[i * 20 + j].push_back(j - 1);
                adjacency_list[i * 20 + j].push_back(j + 1);
                adjacency_list[i * 20 + j].push_back(20 + j);
                adjacency_list[i * 20 + j].push_back(20 + j - 1);
            }
            if (i == 19 && (j > 0 && j < 19))
            {
                adjacency_list[i * 20 + j].push_back(i * 20 + j - 1);
                adjacency_list[i * 20 + j].push_back(i * 20 + j + 1);
                adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j);
            }
            if ((i > 0 && i < 19) && (j > 0 && j < 19))
            {
                adjacency_list[i * 20 + j].push_back(i * 20 + j - 1);
                adjacency_list[i * 20 + j].push_back(i * 20 + j + 1);
                adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adjacency_list[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 0)
                {
                    adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                    adjacency_list[i * 20 + j].push_back((i + 1) * 20 + j - 1);
                }
                else
                {
                    adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                    adjacency_list[i * 20 + j].push_back((i + 1) * 20 + j + 1);
                }
            }
            if ((i > 0 && i < 19) && j == 0)
            {
                adjacency_list[i * 20 + j].push_back(i * 20 + j + 1);
                adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adjacency_list[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 1)
                {
                    adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                    adjacency_list[i * 20 + j].push_back((i + 1) * 20 + j + 1);
                }
            }
            if ((i > 0 && i < 19) && j == 19)
            {
                adjacency_list[i * 20 + j].push_back(i * 20 + j - 1);
                adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adjacency_list[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 0)
                {
                    adjacency_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                    adjacency_list[i * 20 + j].push_back((i + 1) * 20 + j - 1);
                }
            }
        }
    }
}

MainCore::MainCore() {
    gamestatus = 1;
    for (unsigned short int x = 0; x < 20; x++) {
        for (unsigned short int y = 0; y < 20; y++) {
            Map[x][y] = Cell(x, y, window);
            Map_pointer[x][y] = &Map[x][y];
        }
    }
    Player1 = Player(Map_pointer[20][20]);
    Player2 = Player(Map_pointer[0][0]);
    Core = GameCore(Map_pointer, Player1, Player2);

}
