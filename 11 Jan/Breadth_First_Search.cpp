#include<bits/stdc++.h>
using namespace std;

#define v 5
#define totalNodes 100

void addEdge(vector<vector<int>> &graph,int i,int j)
{
    graph[i].push_back(j);
    graph[j].push_back(i);
}

void printMatrix(vector<vector<int>> &graph)
{
    cout <<"Adjacency Matrix: "<<endl;
    for (int i=0; i<graph.size(); i++)
    {
        if(!graph[i].empty())
        {
        cout<<i<<": ";
        for (int neighbour: graph[i])
            {
                cout<<neighbour<<" ";
            }
        cout<<endl;
        }
    }
}

void performBFS(vector<vector<int>> &graph, int startNode)
{
    vector<bool> visited(totalNodes,false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout<<"BFS Traversal: ";

    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        cout<<currentNode<<" ";

        for (int neighbour : graph[currentNode])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    } cout<<endl;
}


int main()
{
    vector<vector<int>> adjMatrix(v);

    addEdge(adjMatrix, 0,1);
    addEdge(adjMatrix, 0,2);
    addEdge(adjMatrix, 2,1);
    addEdge(adjMatrix, 3,1);
    addEdge(adjMatrix, 2,4);
    addEdge(adjMatrix, 4,3);

    printMatrix(adjMatrix);

    performBFS(adjMatrix,0);
}

