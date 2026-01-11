#include<bits/stdc++.h>
using namespace std;

#define v 5

void addEdge(vector<vector<int>> &arr,int i,int j)
{
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void printMatrix(vector<vector<int>> &arr)
{
    int i,j;
    for (i=0; i<v; i++)
    {
        cout<<i<<": ";
        for (int j=0; j<v; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    vector<vector<int>> adjMatrix(v,vector<int>(v,0));

    addEdge(adjMatrix, 0,1);
    addEdge(adjMatrix, 0,2);
    addEdge(adjMatrix, 2,1);
    addEdge(adjMatrix, 3,1);
    addEdge(adjMatrix, 2,4);
    addEdge(adjMatrix, 4,3);

    printMatrix(adjMatrix);
}

