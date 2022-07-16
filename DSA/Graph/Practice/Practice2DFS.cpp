#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


// 1. Given an undirected graph and a source vertex 's' ,print D.F.S. from given source.

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";

    for(int v : adj[s])
    {
        if(visited[v] == false)
        {
            DFSRec(adj, v, visited);
        }
    }
}

void DFS(vector<int> adj[], int v, int s)
{
    bool visited[v] = {false};

    DFSRec(adj, s, visited);
}




// 2. D.F.S on disconnected graphs.


// void DFSRec(vector<int> adj[], int s, bool visited[])
// {
//     visited[s] = true;
//     cout << s << " ";

//     for(int x : adj[s])
//     {
//         if(visited[x] == false)
//         {
//             DFSRec(adj, x, visited);
//         }
//     }

// }

// void DFS(vector<int> adj[], int V)
// {
//     bool visited[V];
//     for(int i = 0; i < V; i++)
//     {
//         visited[i] = false;
//     }

//     for(int i = 0; i < V; i++)
//     {
//         if(visited[i] == false)
//         {
//             DFSRec(adj, i, visited);
//         }
//     }


// }




// 3. Print number of islands in a graph (or number of connected components in a graph).
/*
void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;

    for(int x : adj[s])
    {
        if(visited[x] == false)
        {
            DFSRec(adj, x, visited);
        }
    }
}

int DFS(vector<int> adj[], int V)
{
    int count = 0;
    bool visited[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for(int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        {
            DFSRec(adj, i, visited);
            count++;
        }
    }
    
    return count;
}
*/



int main()
{
    
    // 1. Given an undirected and connected graph and a source vertex 's' ,print D.F.S. from given source.
   int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    int s = 0;
    DFS(adj, V, s);  
     
     /*

    // 2. B.F.S on disconnected graphs.

    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);
    DFS(adj, V);

*/
 
    // 3. Print number of islands in a graph (or number of connected components in a graph).
/*     int V = 10;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);
    addEdge(adj, 4, 7);
    addEdge(adj, 6, 7);
    addEdge(adj, 6, 8);
    addEdge(adj, 7, 8);
    addEdge(adj, 6, 9);
    addEdge(adj, 8, 9);
    cout << DFS(adj, V) << endl; */


    return 0;
}