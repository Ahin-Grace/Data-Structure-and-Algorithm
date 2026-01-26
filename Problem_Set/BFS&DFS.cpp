#include<bits/stdc++.h>
using namespace std;

int totalNodes = 100;

void addEdge(vector<vector<int>> & graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(vector<vector<int>> & graph, int startNode)
{
    vector<bool> visited(totalNodes,false);
    queue<int> que;

    que.push(startNode);
    visited[startNode] = true;

    cout<<"BFS traversal : ";

    while(!que.empty())
    {
        int current = que.front();
        que.pop();
        cout<<current<<" ";
        for(int neighbors: graph[current])
        {
            if(!visited[neighbors])
            {
                que.push(neighbors);
                visited[neighbors]=true;
            }
        }

    }
}

void dfs(vector<vector<int>> & graph, int startNode)
{
    vector<bool> visited(totalNodes,false);
    stack<int> que;

    que.push(startNode);
    visited[startNode] = true;

    cout<<"DFS traversal : ";

    while(!que.empty())
    {
        int current = que.top();
        que.pop();
        cout<<current<<" ";
        for(int neighbors: graph[current])
        {
            if(!visited[neighbors])
            {
                que.push(neighbors);
                visited[neighbors]=true;
            }
        }
    }
}


void printGraph(vector<vector<int>> & graph)
{
    cout<<"Adjacency List: "<<endl;
    for (int i=0;i< graph.size();i++ )
    {if(!graph[i].empty()){
        cout<<i<<": ";



        for(int neighbors : graph[i])
        {
            cout<<neighbors<<" ";
        }
        cout<<endl;
    }}
}

int main()
{
    vector<vector<int>> graph(1000);

    addEdge(graph,10,20);
    addEdge(graph,10,30);
    addEdge(graph,10,40);
    addEdge(graph,20,50);
    addEdge(graph,20,60);
    addEdge(graph,30,60);
    addEdge(graph,30,70);
    addEdge(graph,40,70);
    addEdge(graph,50,80);
    addEdge(graph,60,80);
    addEdge(graph,70,80);

    printGraph(graph);
    bfs(graph,10);
    dfs(graph,10);

}

