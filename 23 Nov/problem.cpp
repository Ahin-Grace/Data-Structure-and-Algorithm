#include<bits/stdc++.h>
using namespace std;
/*
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

}*/


SelectionSort(vector<int> &v,vector <int> &v1)
{
    int n = v.size();
    for (int i=0; i<=n-1; i++)
    {
        int min_index = i;
        for (int j=i+1; j<=n-1; j++){
            if(v1[j]<v1[min_index])
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            swap(v[i],v[min_index]);
            swap(v1[i],v1[min_index]);
        }
    }
}


int main(){
    vector <int> main={-10,-2,5,-3,7};
    vector <int> temp;

    for (int i=0; i<main.size(); i++)
    {
        if (main[i]<0)
        {
            temp.push_back(main[i]*-1);
        }else
        {
            temp.push_back(main[i]);
        }
    }



    SelectionSort(main,temp);

    cout<<endl<<"After Sort :";
    for (int i=0; i<5; i++){
        cout<<" "<<main[i];
    }

    /*
    //Median calculation

    if (n%2==0){
        int x = a[n/2];
        int y = a[(n/2)-1];

        cout<<"Median : "<<(x+y)/2.0;

    }else{
        cout<<"Median : "<<a[n/2];
    }
    */

    /*
    //Minimum difference
    int min_diff=a[1]-a[0];
    for (int i=0; i<=n-2; i++)
    {
        if (min_diff>a[i+1]-a[i])
        min_diff=a[i+1]-a[i];
    }


    cout<<"Minimum difference between elements: "<< min_diff<<endl;
    */










}
