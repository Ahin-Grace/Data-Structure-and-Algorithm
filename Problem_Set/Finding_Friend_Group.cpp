//name: MD. Aminul Islam , ID:0112420710
#include<bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>>&graph,int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void performbfs(vector<vector<int>>&graph,vector<bool>&visited,int start)
{
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        q.pop();
        for(int neighbour:graph[current])
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour]=true;
            }
        }
    }
}
int GroupNumber(vector<vector<int>>&graph,vector<bool>&visited,int total)
{
    int count=0;
    for(int i=0;i<total;i++)
    {
        if(!visited[i])
        {
        performbfs(graph,visited,i);
        count++;
        }
    }
    return count;
}
int main()
{
  int m,n;
    cout<<"Enter the number of vertices:"<<endl;
    cin>>m;
    cout<<"Enter the number of edges:"<<endl;
    cin>>n;
    vector<vector<int>>graph(m);

        for(int i=0;i<n;i++)
    {
        int v,u;
        cout<<"Enter edges:"<<endl;
        cin>>v>>u;
        addedge(graph,v,u);
    }

    vector<bool>visited(m,false);

    cout<<"The total number of group is: "<<GroupNumber(graph,visited,m)<<endl;
}
