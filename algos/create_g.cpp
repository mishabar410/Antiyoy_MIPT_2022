#include <iostream>
#include <vector>


int main() {

    std::vector<std::vector<int>> g(400, std::vector<int>());

    for (unsigned int i = 0; i < 20; i++)
    {
        for (unsigned int j = 0; j < 20; j++)
        {
            if (i == 0 && j == 0)
            {
                g[i * 20 + j].push_back(1);
                g[i * 20 + j].push_back(20);
            }
            if (i == 19 && j == 0)
            {
                g[i * 20 + j].push_back((i - 1) * 20);
                g[i * 20 + j].push_back(i * 20 + 1);
            }
            if (i == 0 && j == 19)
            {
                g[i * 20 + j].push_back(18);
                g[i * 20 + j].push_back(38);
                g[i * 20 + j].push_back(39);
            }
            if (i == 19 && j == 19)
            {
                g[i * 20 + j].push_back(i * 20 + j - 1);
                g[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                g[i * 20 + j].push_back((i - 1) * 20 + j);
            }
            if (i == 0 && (j > 0 && j < 19))
            {
                g[i * 20 + j].push_back(j - 1);
                g[i * 20 + j].push_back(j + 1);
                g[i * 20 + j].push_back(20 + j);
                g[i * 20 + j].push_back(20 + j - 1);
            }
            if (i == 19 && (j > 0 && j < 19))
            {
                g[i * 20 + j].push_back(i * 20 + j - 1);
                g[i * 20 + j].push_back(i * 20 + j + 1);
                g[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                g[i * 20 + j].push_back((i - 1) * 20 + j);
            }
            if ((i > 0 && i < 19) && (j > 0 && j < 19))
            {
                g[i * 20 + j].push_back(i * 20 + j - 1);
                g[i * 20 + j].push_back(i * 20 + j + 1);
                g[i * 20 + j].push_back((i - 1) * 20 + j);
                g[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 0)
                {
                    g[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                    g[i * 20 + j].push_back((i + 1) * 20 + j - 1);
                }
                else
                {
                    g[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                    g[i * 20 + j].push_back((i + 1) * 20 + j + 1);
                }
            }
            if ((i > 0 && i < 19) && j == 0)
            {
                g[i * 20 + j].push_back(i * 20 + j + 1);
                g[i * 20 + j].push_back((i - 1) * 20 + j);
                g[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 1)
                {
                    g[i * 20 + j].push_back((i - 1) * 20 + j + 1);
                    g[i * 20 + j].push_back((i + 1) * 20 + j + 1);
                }
            }
            if ((i > 0 && i < 19) && j == 19)
            {
                g[i * 20 + j].push_back(i * 20 + j - 1);
                g[i * 20 + j].push_back((i - 1) * 20 + j);
                g[i * 20 + j].push_back((i + 1) * 20 + j);
                if (i % 2 == 0)
                {
                    g[i * 20 + j].push_back((i - 1) * 20 + j - 1);
                    g[i * 20 + j].push_back((i + 1) * 20 + j - 1);
                }
            }
        }
    }
    for (unsigned int i = 0; i < 400; i++) {
        std::cout << i << ": ";
        for (unsigned int j = 0; j < g[i].size(); j++) {
            std::cout << g[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
