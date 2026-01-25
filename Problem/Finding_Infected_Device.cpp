//name: MD. Aminul Islam , ID:0112420710
#include<bits/stdc++.h>
using namespace std;
void addedge(vector<vector<int>>&graph,int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int bfs(vector<vector<int>>&graph,vector<bool>&visited,int start)
{
    int minute=0;
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        minute++;
        for(int neibour:graph[current])
        {
            if(!visited[neibour])
            {
                q.push(neibour);
                visited[neibour]=true;
            }
        }
    }
   return minute-1;
}
int DetectMinutes(vector<vector<int>>&graph,vector<bool>&visited,int total)
{
    int c=0;
    int minute=0;
    for(int i=0;i<total;i++)
    {
        if(!visited[i])
        {
            minute=bfs(graph,visited,i);
            c++;
        }
        if(c>1)
        {
            cout<<"the number of infected computer is:"<<endl;
            return -1;
        }

    }
    return minute;
}
int main()
{
  int total,m;
    cout<<"Enter the number of vertices:"<<endl;
    cin>>total;
    cout<<"Enter the number of edges:"<<endl;
    cin>>m;
    vector<vector<int>>graph(total);

        for(int i=0;i<m;i++)
    {
        int v,u;
        cout<<"Enter edges:"<<endl;
        cin>>v>>u;
        addedge(graph,v,u);
    }

    vector<bool>visited(total,false);
    cout<<"the number of minutes required: "<<DetectMinutes(graph,visited,total)<<endl;

}
