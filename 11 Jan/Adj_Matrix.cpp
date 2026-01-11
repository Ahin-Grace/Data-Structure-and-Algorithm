#include<bits/stdc++.h>
using namespace std;

#define v 5

void init(int arr[][v])
{
    int i,j;
    for (int i=0; i<v; i++)
        for (int j=0; j<v; j++)
            arr[i][j] = 0;
}

void addEdge(int arr[][v],int i,int j)
{
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void printMatrix(int arr[][v])
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
    int adjMatrix[v][v];

    init(adjMatrix);

    addEdge(adjMatrix, 0,1);
    addEdge(adjMatrix, 0,2);
    addEdge(adjMatrix, 2,1);
    addEdge(adjMatrix, 3,1);
    addEdge(adjMatrix, 2,4);
    addEdge(adjMatrix, 4,3);

    printMatrix(adjMatrix);
}
