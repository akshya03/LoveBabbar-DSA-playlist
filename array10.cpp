#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j;
    cout<<"enter no. of elements:";
    cin>>n;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];

    j=0;
    for(i=0;i<n;++i){
        if(arr[i]<0)
            swap(arr[i],arr[j++]);
    }
    for(int x:arr)
        cout<<x<<" ";
}
