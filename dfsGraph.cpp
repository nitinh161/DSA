#include <iostream>
using namespace std;
void dfs(int v, vector<int> adj[], vector<int> &ans, vector<bool> &vis)
{

    if (vis[v])
        return;

    vis[v] = true;
    ans.push_back(v);

    for (auto child : adj[v])
    {
        dfs(child, adj, ans, vis);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> vis(V, false);

    dfs(0, adj, ans, vis);

    return ans;
}

;
int main()
{

    return 0;
}