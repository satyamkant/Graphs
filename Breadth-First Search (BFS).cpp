//Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

vector<int> bfs_traversal(vector<int> adj[], int n)
{
    //declaring bfs array to store the bfs traversal...
    vector<int> bfs;
    //declaring visited array...
    vector<int> vis(n + 1, 0);

    //if the graph is disconnected...this for loop will take care of that
    for (int i = 1; i <= n; i++)
    {
        //visited array is required to avoid cycles and
        //also to move to other disconnected component...
        if (!vis[i])
        {
            //declaring queue for bfs...
            queue<int> qu;
            //nodes are zero base index...
            qu.push(i);
            vis[i] = 1;
            while (!qu.empty())
            {
                int node = qu.front();
                qu.pop();
                bfs.push_back(node);
                //traversing all of the children of the current parent... i.e. bfs
                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        //pushing the child node into the queue...
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
