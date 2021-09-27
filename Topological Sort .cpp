// note: topo sort using BFS is also called as Kahn's algorithm
//Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

class Topo_sort
{
    vector<int> bfs_Topo_Sort(vector<int> adj[], vector<int> &indegree, int n)
    {
        vector<int> vis(n + 1, 0), srt_arr;
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
                    srt_arr.push_back(node);
                    vis[node] = 1;
                    for (auto it : adj[node])
                    {
                        indegree[it]--;
                        if (indegree[it] == 0)
                            qu.push(it);
                    }
                }
            }
        }

        return srt_arr;
    }

    void dfs_Topo_Sort(vector<int> adj[], vector<int> &vis, stack<int> &st, int node)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs_Topo_Sort(adj, vis, st, it);
            }
        }
        st.push(node);
    }

public:
    vector<int> TopoSortUsing_bfs(vector<int> adj[], int n)
    {
        vector<int> indegree(n + 1, 0);
        //creating indegree array...
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }

        return bfs_Topo_Sort(adj, indegree, n);
    }

    vector<int> TopoSortUsing_dfs(vector<int> adj[], int n)
    {
        vector<int> vis(n + 1, 0), srt_arr;
        stack<int> st;
        //if the graph is disconnected...then this for loop will take care of that
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs_Topo_Sort(adj, vis, st, i);
            }
        }

        while (!st.empty())
        {
            srt_arr.push_back(st.top());
            st.pop();
        }
        return srt_arr;
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
        //topo sort can only be applied to directed Acyclic graphs...
        //adj[v].push_back(u);
    }
    //declaring object...
    Topo_sort topo;
    vector<int> sort_bfs = topo.TopoSortUsing_bfs(adj, n), sort_dfs = topo.TopoSortUsing_dfs(adj, n);

    for (auto it : sort_bfs)
        cout << it << " ";
    cout << endl;
    for (auto it : sort_dfs)
        cout << it << " ";
    return 0;
}