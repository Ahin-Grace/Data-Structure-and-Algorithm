#include<bits/stdc++.h>
using namespace std;


int BinarySearch(vector<int> &arr, int n, int key)
{
    int low =0;
    int high = n-1;

    while(low<=high)
    {
        int mid =(low+high)/2;
        if(arr[mid]==key)
        {
            return mid;
        }else if(arr[mid]>key)
        {
            high = mid-1;
        }else
        {
            low = mid+1;
        }
    }
    return low;
}


int main()
{
    vector<int> v = {1,2,3,5,6,8,10};//For binary Search the array/vector needs to be sorted
    int key;
    cout<<"Enter the number you need to search: ";
    cin>>key;
    int num=BinarySearch(v,v.size(),key);
    if(num==-1)
    {
        cout<<"The number not found"<<endl;
    }else
    {
        cout<<"The number "<<key<<" should be inserted is at index "<<num<<endl;
    }
}


