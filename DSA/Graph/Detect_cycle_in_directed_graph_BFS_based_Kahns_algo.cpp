#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

//same as Topological Sorting, just count variable introduced
// Kahn's algorithm
bool DetectCycle(vector<int> adj[], int V)
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

    int count = 0;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for (int x : adj[u])
        {
            indegree[x]--;
            if(indegree[x] == 0)
                q.push(x);
        }

        count++;
    }

    if(count != V)
        return true;
    
    return false;
}

int main()
{
    int V = 4;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    cout << std::boolalpha;
    cout << DetectCycle(adj, V) << endl;

    return 0;
}