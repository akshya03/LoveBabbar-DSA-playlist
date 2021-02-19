#include<bits/stdc++.h>
using namespace std;

int first(int arr[],int l,int h,int x){
    if(l>h)
        return -1;
    int mid=l+(h-l)/2;

    if(arr[mid]==x && (mid==0 || x>arr[mid-1]))
        return mid;
    else if(x>arr[mid])
        return first(arr,mid+1,h,x);
    else
        return first(arr,l,mid-1,x);
}

int last(int arr[],int l,int h,int x,int n){
    if(l>h)
        return -1;
    int mid=l+(h-l)/2;

    if(arr[mid]==x && (mid==n-1 || x<arr[mid+1]))
        return mid;
    else if(x<arr[mid])
        return last(arr,l,mid-1,x,n);
    else
        return last(arr,mid+1,h,x,n);
}

void recursive(int arr[],int n,int x){
    int f,l;
    f=first(arr,0,n-1,x);

    if(f!=-1)
        l=last(arr,f,n-1,x,n);
    else
        l=-1;
    cout<<"Recursive:"<<f<<" "<<l<<endl;
}

int main(){
    int n,i,x;
    cin>>n>>x;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];
    recursive(arr,n,x);
    //iterative(arr,n,x);

    return 0;
}
