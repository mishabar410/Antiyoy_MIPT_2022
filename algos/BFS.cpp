#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


int main() {
    int n, tmp;
    std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>());
    for(unsigned int i = 0; i < n; i++)
    {
        for(unsigned int j = 0; j < n; j++)
        {
            std::cin >> tmp;
            if (tmp)
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    int s, to;
    std::cin >> s >> to;
    s--;
    to--;

    std::queue<int> q;
    q.push (s);
    std::vector<bool> used (n);
    std::vector<int> d (n), p (n);
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

    if (!used[to]) std::cout << -1;
    else
    {
    	std::vector<int> path;
    	for (int v = to; v != -1; v = p[v]) path.push_back(v);
    	std::reverse (path.begin(), path.end());
        std::cout << path.size() - 1 << std::endl;
        if (path.size() - 1 > 0)
        {
            for (unsigned int i = 0; i < path.size(); ++i)
                std::cout << path[i] + 1 << " ";
        }
    }

    return 0;
}
