#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

int main() {
    int n, tmp;
    cin >> n;
    vector<vector<int>> g(n, vector<int>());
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> tmp;
            if (tmp)
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    int s, to;
    cin >> s >> to;
    s--;
    to--;

    queue<int> q;
    q.push (s);
    vector<bool> used (n);
    vector<int> d (n), p (n);
    used[s] = true;
    p[s] = -1;
    while (!q.empty())
    {
    	int v = q.front();
    	q.pop();
    	for (size_t i = 0; i < g[v].size(); ++i)
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

    if (!used[to]) cout << -1;
    else
    {
    	vector<int> path;
    	for (int v = to; v != -1; v = p[v]) path.push_back(v);
    	reverse (path.begin(), path.end());
        cout << path.size() - 1 << endl;
        if (path.size() - 1 > 0)
        {
            for (size_t i = 0; i < path.size(); ++i)
                cout << path[i] + 1 << " ";
        }
    }

    return 0;
}
