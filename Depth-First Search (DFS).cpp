#include <bits/stdc++.h>

using namespace std;

void dfs_traversal(int node, vector<int> adj[], vector<int> &dfs, vector<int> &vis)
{
    dfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs_traversal(it, adj, dfs, vis);
        }
    }
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
    vector<int> dfs;
    vector<int> vis(n + 1, 0);
    //if the graph is disconnected...then this for loop will take care of that
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs_traversal(i, adj, dfs, vis);
        }
    }
    for (auto it : dfs)
        cout << it << " ";
    return 0;
}