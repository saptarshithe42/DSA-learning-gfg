#include<iostream>
#include<vector>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

// DFS approach
bool DFSRec(vector<int> adj[], int s, bool visited[], bool recSt[])
{
    visited[s] = true;
    recSt[s] = true;

    for(int u : adj[s])
    {
        if(visited[u] == false && DFSRec(adj, u, visited, recSt))
        {
            return true;
        }
        else if (recSt[u] == true)
        {
            return true;
        }
    }

    recSt[s] = false;   
    return false;
}

bool DFS(vector<int> adj[], int V)
{
    bool visited[V];
    bool recSt[V];

    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recSt[i] = false;
    }

    for(int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        {
            if(DFSRec(adj, i, visited, recSt) == true)
                return true;
        }
    }

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

    cout << DFS(adj, V) << endl;


    
    return 0;
}