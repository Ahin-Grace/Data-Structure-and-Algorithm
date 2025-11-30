#include<bits/stdc++.h>
using namespace std;


int LinearSearch(vector<int> &arr, int n, int key)
{
    for(int i=0; i<=n-1; i++)
    {
        if (arr[i]==key)  return i;
    }
    return -1;
}



int main()
{
    vector<int> v = {5,10,2,6,4,3,1};

    int key;
    cout<<"Enter the number you need to search: ";
    cin>>key;

    int num=LinearSearch(v,v.size(),key);
    if(num==-1)
    {
        cout<<"The number not found"<<endl;
    }else
    {
        cout<<"The number is at index "<<num<<endl;
    }


}
