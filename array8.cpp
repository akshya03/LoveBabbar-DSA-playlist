//https://www.youtube.com/watch?v=fnbImb8lo88&t=264s
//solved using QuickSelect algo
#include<bits/stdc++.h>
using namespace std;

//sorting in descending order
int kthLargest(int arr[], int l, int r, int k) {
    if(k>r)
        return -1;
    int pivot,i,j;
    pivot=arr[r];

    i=l-1;
    for(j=l;j<r;++j){
        if(arr[j]>pivot){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[++i],arr[r]);
    if(i==k)
        return arr[i];
    else if(i<k)
        return kthLargest(arr,i+1,r,k);
    else
        return kthLargest(arr,l,i-1,k);
}

int kthSmallest(int arr[], int l, int r, int k) {
    nth_element(arr, arr + k - 1, arr+(r+1));
    return arr[k-1];
}

int main(){
    int n,i,k;
    cout<<"Enter value of n,k for kth largest element:";
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];
    //for kth largest
    cout<<kthLargest(arr,0,n-1,k-1)<<endl;
    cout<<kthSmallest(arr,0,r,k)<<endl;
    for(i=0;i<n;++i)
        cout<<arr[i]<<" ";
    return 0;
}
