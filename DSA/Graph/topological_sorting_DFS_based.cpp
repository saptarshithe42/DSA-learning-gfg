#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void DFSRec(vector<int> adj[], int s, bool visited[], stack<int> &st)
{
    visited[s] = true;

    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            DFSRec(adj, u, visited, st);
        }
    }

    st.push(s);
}

void topological_sorting(vector<int> adj[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSRec(adj, i, visited, st);
        }
    }

    while (st.empty() == false)
    {
        int u = st.top();
        st.pop();
        cout << u << " ";
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 4);
    // addEdge(adj, 2, 4);


    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);

    topological_sorting(adj, V);

    return 0;
}