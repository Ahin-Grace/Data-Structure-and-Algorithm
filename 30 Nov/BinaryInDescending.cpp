#include<bits/stdc++.h>
using namespace std;


int BinarySearch(vector<int> &arr, int key, int low,int high)
{

    if(low>high) return -1;
    int mid =(low+high)/2;
    if(arr[mid]==key)
    {
        return mid;
    }else if(arr[mid]>key)
    {
        BinarySearch(arr,key,mid+1,high);
    }else
    {
        BinarySearch(arr,key,low,mid-1);
    }
}


int main()
{
    vector<int> v = {9,7,5,3,1};//For binary Search the array/vector needs to be sorted
    int key;
    cout<<"Enter the number you need to search: ";
    cin>>key;
    int num=BinarySearch(v,key,0,v.size()-1);
    if(num==-1)
    {
        cout<<"The number not found"<<endl;
    }else
    {
        cout<<"The number "<<key<<" is at index "<<num<<endl;
    }
}



