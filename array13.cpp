//Kadane's Algorithm
//contiguous sub-array with maximum sum
#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    int ans,i,j,k;
}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];
    cout<<maxSubarraySum(arr,n)<<endl;
    return 0;
}
