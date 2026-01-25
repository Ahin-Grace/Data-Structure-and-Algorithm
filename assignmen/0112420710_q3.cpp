//name: MD. Aminul Islam , ID:0112420710
#include<bits/stdc++.h>
using namespace std;
void addedge(vector<vector<int>>&graph,int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int LargestDistance(vector<vector<int>>&graph,int start,int total)
{
    vector<bool>visited(total,false);
    vector<int>distance(total,0);
    int max=distance[0];
    queue<int>q;
    q.push(start);
    visited[start]=true;
    distance[start]=0;
    while(!q.empty())
    {
        int current=q.front();
        q.pop();

        for(int neighbour:graph[current])
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour]=true;
                distance[neighbour]=distance[current]+1;
            }
        }

        for(int i=0;i<total;i++)
        {
            if(distance[i]>max)
            {
                max=distance[i];
            }
        }
    }
    for(int i=0;i<total;i++)
    {
        if(!visited[i])
            return -1;
    }

   return max;
}

int main()
{
   int total,n;
    cout<<"Enter the number of vertices:"<<endl;
    cin>>total;
    cout<<"Enter the number of edges:"<<endl;
    cin>>n;
    vector<vector<int>>graph(total);

    for(int i=0;i<n;i++)
    {
        int v,u;
        cout<<"Enter edges:"<<endl;
        cin>>v>>u;
        addedge(graph,v,u);
    }

    cout<<"The farthest node from 0 is : ";
    cout<<LargestDistance(graph,0,total);

}
