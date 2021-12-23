// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

class Bipartite_Check
{
    bool bfs_Bipartite_Check(vector<int> adj[], vector<int> &color, int n)
    {
        // if the graph is disconnected...then this for loop will take care of that
        for (int i = 0; i < n; i++)
        {
            // the color array will also act as visited array...
            if (color[i] == -1)
            {
                // creating queue for bfs...
                queue<int> qu;
                // pushing the parent inside the queue first...
                qu.push(i);
                // starting with color 1 i.e. assigning 1 to color array for current node...
                color[i] = 1;

                while (!qu.empty())
                {
                    int node = qu.front();
                    qu.pop();
                    // traversing the child of the current node...
                    for (auto it : adj[node])
                    {
                        if (color[it] == -1)
                        {
                            // assigning opposite color of parent to the child...
                            color[it] = 1 - color[node];
                            // since we have assigned color to this child then we will push it in the queue so
                            // we will assign color to the children of this child...
                            qu.push(it);
                        }
                        else if (color[it] == color[node]) // color of the child is same as the color of the parent...
                            return false;                  // i.e. not a bipertite graph...
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
                // providing opposite color to the child...
                color[it] = 1 - color[node];
                if (!dfs_Bipartite_Check(adj, color, it))
                    return false;
            }
            else if (color[it] == color[node]) // color of the child is same as color of the parent
                return false;                  // i.e. same color at adjacent nodes...not bipertite
        }
        return true;
    }

public:
    bool CheckUsing_bfs(vector<int> adj[], int n)
    {
        // declaring color array...
        vector<int> color(n + 1, -1);
        return bfs_Bipartite_Check(adj, color, n);
    }

    bool CheckUsing_dfs(vector<int> adj[], int n)
    {
        // declaring color array...
        vector<int> color(n + 1, -1);

        // if the graph is disconnected...then this for loop will take care of that
        for (int i = 0; i < n; i++)
        {
            // the color array will also act as visited array...
            if (color[i] == -1)
            {
                // starting with color 1 and then alternating...
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
    // n nodes and m edges
    int n, m;

    cin >> n >> m;

    // declaring adjacency list...
    vector<int> adj[n + 1];

    // for input...
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // declaring object...
    Bipartite_Check check;

    // using bfs...
    if (check.CheckUsing_bfs(adj, n))
        cout << "YES";
    else
        cout << "NO";
    // using dfs...
    if (check.CheckUsing_dfs(adj, n))
        cout << "\nYES";
    else
        cout << "\nNO";

    return 0;
}