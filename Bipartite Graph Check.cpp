#include <bits/stdc++.h>

using namespace std;

class Bipartite_Check
{
    bool bfs_Bipartite_Check(vector<int> adj[], vector<int> &color, int n)
    {
        //if the graph is disconnected...then this for loop will take care of that
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                queue<int> qu;
                qu.push(i);
                color[i] = 1;
                while (!qu.empty())
                {
                    int node = qu.front();
                    qu.pop();
                    for (auto it : adj[node])
                    {
                        if (color[it] == -1)
                        {
                            color[it] = 1 - color[node];
                            qu.push(it);
                        }
                        else if (color[it] == color[node])
                            return false;
                    }
                }
            }
        }
        return true;
    }

    bool dfs_Bipartite_Check(vector<int> adj[], vector<int> &color, int node)
    {
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                if (!dfs_Bipartite_Check(adj, color, it))
                    return false;
            }
            else if (color[it] == color[node])
                return false;
        }
        return true;
    }

public:
    bool CheckUsing_bfs(vector<int> adj[], int n)
    {
        vector<int> color(n + 1, -1);
        return bfs_Bipartite_Check(adj, color, n);
    }

    bool CheckUsing_dfs(vector<int> adj[], int n)
    {
        vector<int> color(n + 1, -1);

        //if the graph is disconnected...then this for loop will take care of that
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 1;
                if (!dfs_Bipartite_Check(adj, color, i))
                    return false;
            }
        }
        return true;
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
    Bipartite_Check check;

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