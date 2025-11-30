#include<bits/stdc++.h>
using namespace std;


vector<int> LinearSearch(vector<int> &arr, int n, int key)
{
    vector<int> v1;
    for(int i=0; i<=n-1; i++)
    {
        if (arr[i]==key)  v1.push_back(i);
    }
    return v1;
}



int main()
{
    vector<int> v = {5,10,2,6,4,3,1,2,5,2,7,2};

    int key;
    cout<<"Enter the number you need to search: ";
    cin>>key;

    vector<int> num=LinearSearch(v,v.size(),key);

    if (num.size()==0)
    {
        cout<<"The number not found"<<endl;
    }else{
        for (int i: num)
        {
            cout<<i<<" ";
        }
    }
}
