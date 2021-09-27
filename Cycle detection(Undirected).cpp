//Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

class Cycle_Check
{
    bool bfs_Cycle_Check(vector<int> adj[], vector<int> &vis, int n)
    {
        //if the graph is disconnected...then this for loop will take care of that
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                //first value contains the current node and second value contains the parent node...
                queue<pair<int, int>> qu;
                qu.push({i, -1});
                vis[i] = 1;
                while (!qu.empty())
                {
                    int node = qu.front().first;
                    int par = qu.front().second;
                    qu.pop();
                    for (auto it : adj[node])
                    {
                        if (!vis[it])
                        {
                            vis[it] = 1;
                            qu.push({it, node});
                        }
                        else if (it != par)
                            return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs_Cycle_Check(vector<int> adj[], vector<int> &vis, int node, int par)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs_Cycle_Check(adj, vis, it, node))
                    return true;
            }
            else if (it != par)
                return true;
        }
        return false;
    }

public:
    bool CheckUsing_bfs(vector<int> adj[], int n)
    {
        vector<int> vis(n + 1, 0);
        return bfs_Cycle_Check(adj, vis, n);
    }
    bool CheckUsing_dfs(vector<int> adj[], int n)
    {
        vector<int> vis(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (dfs_Cycle_Check(adj, vis, i, -1))
                    return true;
            }
        }
        return false;
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
    //declaring object...
    Cycle_Check check;

    //using bfs...
    if (check.CheckUsing_bfs(adj, n))
        cout << "YES";
    else
        cout << "NO";
    //using dfs...
    if (check.CheckUsing_dfs(adj, n))
        cout << "\nYES";
    else
        cout << "\nNO";

    return 0;
}