#include <bits/stdc++.h>

using namespace std;

vector<int> bfs_traversal(vector<int> adj[], int n)
{
    vector<int> bfs;
    vector<int> vis(n + 1, 0);
    //if the graph is disconnected...this for loop will take care of that
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<int> qu;
            //nodes are zero base index...
            qu.push(i);
            vis[i] = 1;
            while (!qu.empty())
            {
                int node = qu.front();
                qu.pop();
                bfs.push_back(node);
                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        qu.push(it);
                    }
                }
            }
        }
    }
    return bfs;
}

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
    vector<int> bfs = bfs_traversal(adj, n);
    for (auto it : bfs)
        cout << it << " ";
    return 0;
}
