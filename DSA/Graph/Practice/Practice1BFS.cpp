#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}   

void BFS(vector<int> adj[], int v, int s)
{
    bool visited[v] = {false};
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while(q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int x : adj[u])
        {
            if(visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}



int main()
{

    // 1. Given an undirected and connected graph and a source vertex 's' ,print B.F.S. from given source.
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    int s = 0;
    BFS(adj, V, s); 
     

    // 2. B.F.S on disconnected graphs.

    // int V = 7;
    // vector<int> adj[V];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 2, 3);

    // addEdge(adj, 4, 5);
    // addEdge(adj, 5, 6);
    // addEdge(adj, 4, 6);
    // BFSDis(adj, V);


    // 3. Print number of islands in a graph (or number of connected components in a graph).
    // int V = 10;
    // vector<int> adj[V];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 2, 3);

    // addEdge(adj, 4, 5);
    // addEdge(adj, 5, 6);
    // addEdge(adj, 4, 6);
    // addEdge(adj, 4, 7);
    // addEdge(adj, 6, 7);
    // addEdge(adj, 6, 8);
    // addEdge(adj, 7, 8);
    // addEdge(adj, 6, 9);
    // addEdge(adj, 8, 9);
    // cout << BFSDis(adj, V) << endl;


    return 0;
}