#include <bits/stdc++.h>

using namespace std;

class shortest_path
{
    vector<int> bfs(vector<int> adj[], vector<int> &dist, int source)
    {
        queue<int> qu;
        qu.push(source);
        dist[source] = 0;
        while (!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            for (auto it : adj[node])
            {
                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = dist[node] + 1;
                    qu.push(it);
                }
            }
        }
    }

public:
    int maxn = INT_MAX;
    vector<int> Find_path(vector<int> adj[], int n)
    {
        vector<int> dist(n + 1, maxn);
        //setting the source as 0...
        bfs(adj, dist, 0);
        return dist;
    }
};

int main()
{
    //n nodes and m edges
    int n, m;

    cin >> n >> m;

    //declaring adjacency list...
    vector<int> adj[n + 1];

    //for input...
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    shortest_path srt_path;
    vector<int> dist = srt_path.Find_path(adj, n);
    for (auto it : dist)
        cout << it << " ";
    return 0;
}
