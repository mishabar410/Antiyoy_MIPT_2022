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


void MainCore::fill_adj_list():
{
    for (unsigned int i = 0; i < 20; i++)
    {
        for (unsigned int j = 0; j < 20; j++)
        {
            if (i == 0 && j == 0)
            {
                adj_list[i * 20 + j].push_back(1);
                adj_list[i * 20 + j].push_back(20);
            }
            if (i == 19 && j == 0)
            {
                adj_list[i * 20 + j].push_back((i - 1) * 20);
                adj_list[i * 20 + j].push_back(i * 20 + 1);
            }
            if (i == 0 && j == 19)
            {
                adj_list[i * 20 + j].push_back(18);
                adj_list[i * 20 + j].push_back(38);
                adj_list[i * 20 + j].push_back(39);
            }
            if (i == 19 && j == 19)
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
            }
            if (i == 0 && (j > 0 && j < 19))
            {
                adj_list[i * 20 + j].push_back(j - 1);
                adj_list[i * 20 + j].push_back(j + 1);
                adj_list[i * 20 + j].push_back(20 + j);
                adj_list[i * 20 + j].push_back(20 + j - 1);
            }
            if (i == 19 && (j > 0 && j < 19))
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                adj_list[i * 20 + j].push_back(i * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
            }
            if ((i > 0 && i < 19) && (j > 0 && j < 19))
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                adj_list[i * 20 + j].push_back(i * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adj_list[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 0)
                {
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                    adj_list[i * 20 + j].push_back((i + 1) * 20 + j - 1);
                }
                else
                {
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                    adj_list[i * 20 + j].push_back((i + 1) * 20 + j + 1);
                }
            }
            if ((i > 0 && i < 19) && j == 0)
            {
                adj_list[i * 20 + j].push_back(i * 20 + j + 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adj_list[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 1)
                {
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                    adj_list[i * 20 + j].push_back((i + 1) * 20 + j + 1);
                }
            }
            if ((i > 0 && i < 19) && j == 19)
            {
                adj_list[i * 20 + j].push_back(i * 20 + j - 1);
                adj_list[i * 20 + j].push_back((i - 1) * 20 + j);
                adj_list[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 0)
                {
                    adj_list[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                    adj_list[i * 20 + j].push_back((i + 1) * 20 + j - 1);
                }
            }
        }
    }
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