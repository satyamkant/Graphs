#include <bits/stdc++.h>

using namespace std;

class Cycle_Check
{
    //using Kahn's algorithm in bfs...
    bool bfs_Cycle_Check(vector<int> adj[], vector<int> &indegree, int n)
    {
        vector<int> vis(n + 1, 0);
        int cnt = 0;
        //if the graph is disconnected...then this for loop will take care of that
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                queue<int> qu;
                for (int i = 0; i < n; i++)
                {
                    if (indegree[i] == 0)
                        qu.push(i);
                }

                while (!qu.empty())
                {
                    int node = qu.front();
                    qu.pop();
                    vis[node] = 1;
                    cnt++;
                    for (auto it : adj[node])
                    {
                        indegree[it]--;
                        if (indegree[it] == 0)
                            qu.push(it);
                    }
                }
            }
        }

        return !(cnt == n);
    }

    bool dfs_Cycle_Check(vector<int> adj[], vector<int> &vis, vector<int> &dfs_vis, int node)
    {
        vis[node] = 1;
        dfs_vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs_Cycle_Check(adj, vis, dfs_vis, it))
                    return true;
            }
            else if (dfs_vis[it])
                return true;
        }
        dfs_vis[node] = 0;
        return false;
    }

public:
    bool CheckUsing_bfs(vector<int> adj[], int n)
    {
        vector<int> indegree(n + 1, 0);
        //creating indegree array...
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }
        return bfs_Cycle_Check(adj, indegree, n);
    }

    bool CheckUsing_dfs(vector<int> adj[], int n)
    {
        vector<int> vis(n + 1, 0), dfs_vis(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (dfs_Cycle_Check(adj, vis, dfs_vis, i))
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
        //since this is directed graph...
        //adj[v].push_back(u);
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