//rotate array in clockwise direction once
#include<bits/stdc++.h>
using namespace std;

void solve(int *arr,int n){
    int i,temp=arr[n-1];
    for(i=n-2;i>-1;--i){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];
    solve(arr,n);
    for(int x:arr)
        cout<<x<<" ";
}
