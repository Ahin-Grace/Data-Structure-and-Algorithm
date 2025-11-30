#include<bits/stdc++.h>
using namespace std;
/*
InsertionSort(int arr[],int n){
    for (int i=1; i<n; i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]= key;
    }
}


int main(){
    int a[5]={5,6,4,1,2};

    cout<<"Before Sort :";
    for (int i=0; i<5; i++){
        cout<<" "<<a[i];
    }

    InsertionSort(a,5);
    cout<<endl<<"After Sort :";
    for (int i=0; i<5; i++){
        cout<<" "<<a[i];
    }


}
*/


InsertionSort(vector <int> &v1,int n){
    for (int i=1; i<n; i++){
        int key=v1[i];
        int j=i-1;
        while(j>=0 && v1[j]>key){
            v1[j+1]=v1[j];
            j--;
        }
        v1[j+1]= key;
    }
}


int main(){
    vector<int> v = {5,6,4,1,2};

    cout<<"Before Sort :";
    for (int i=0; i<5; i++){
        cout<<" "<<v[i];
    }

    InsertionSort(v,v.size());
    cout<<endl<<"After Sort :";
    for (int i=0; i<5; i++){
        cout<<" "<<v[i];
    }


}
