//find Largest sum contiguous Subarray [V. IMP] (Kadane's Algorithm)
#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    int currentBest,overallBest,i,j,x,y,overall_x,overall_y;
    currentBest=overallBest=x=y=overall_x=overall_y=0;

    for(i=0;i<n;++i){
        if(currentBest<0){ //if currentBest<0, max will start from arr[i] no matter positive or negative
            currentBest=arr[i];
            x=y=i;
        }
        else{
            currentBest+=arr[i];
            y=i;
        }

        if(currentBest>overallBest || i==0){    //i==0 checked if 1st element is least neagtive eg: -1,-2,-3,-4 ans=-1 and not 0
            overallBest=currentBest;
            overall_x=x;
            overall_y=y;
        }

    }
    for(i=overall_x;i<=overall_y;++i)
        cout<<arr[i]<<" ";
    cout<<endl;

    return overallBest;
}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];
    cout<<maxSubarraySum(arr,n)<<"=Max sum obtained";
    return 0;
}
