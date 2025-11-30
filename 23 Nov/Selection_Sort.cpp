#include<bits/stdc++.h>
using namespace std;

SelectionSort(int arr[],int n)
{
    for (int i=0; i<=n-2; i++)
    {
        int min_index = i;
        for (int j=i+1; j<=n-1; j++){
            if(arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            swap(arr[i],arr[min_index]);
        }

    }

}

int main(){
    int a[]={5,6,4,1,2};

    cout<<"Before Sort :";
    for (int i=0; i<5; i++){
        cout<<" "<<a[i];
    }

    int n= sizeof(a)/sizeof(a[0]);
    SelectionSort(a,n);
    cout<<endl<<"After Sort :";
    for (int i=0; i<5; i++){
        cout<<" "<<a[i];
    }

}
