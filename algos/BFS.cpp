#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


int main() {
    int n, tmp;
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


    for (std::size_t i = 0; i < 400; i++)
    {
        std::sort(g[i].begin(), g[i].end());
    }
    

    int s, to;
    std::cin >> s;


    std::queue<int> q;
    q.push (s);
    std::vector<bool> used (400);
    std::vector<int> d (400), p (400);
    used[s] = true;
    p[s] = -1;
    while (!q.empty())
    {
    	int v = q.front();
    	q.pop();
    	for (unsigned int i = 0; i < g[v].size(); ++i)
        {
    		int to = g[v][i];
    		if (!used[to])
            {
    			used[to] = true;
    			q.push (to);
    			d[to] = d[v] + 1;
    			p[to] = v;
    		}
    	}
    }

    std::vector<int> can_go;
    for (std::size_t to = 0; to < 400; to++)
    {

        std::vector<int> path;
        for (int v = to; v != -1; v = p[v])
            path.push_back(v);
        std::reverse(path.begin(), path.end());
        if (path.size() - 1 < 3) can_go.push_back(to);
    }
    
    for (std::size_t i = 0; i < can_go.size(); i++)
    {
        std::cout << can_go[i] << " ";
    }

    return 0;
}
