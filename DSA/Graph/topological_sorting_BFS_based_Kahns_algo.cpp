#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

// Topological Sorting
// Kahn's algorithm
void topological_sorting(vector<int> adj[], int V)
{
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (int u : adj[i])
            indegree[u]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int x : adj[u])
        {
            indegree[x]--;
            if(indegree[x] == 0)
                q.push(x);
        }
    }
}

int main()
{
    int V = 4;
    vector<int> adj[V];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);

    topological_sorting(adj, V);

    return 0;
}