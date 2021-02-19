//https://www.youtube.com/watch?v=phgjL7SbsWs&ab_channel=Pepcoding

#include<bits/stdc++.h>
using namespace std;

void display(int *arr,int n){
  for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
  cout<<endl;
}

int minSteps(int *arr,int n){
    int i,j,ans,jumpSize,dp[n]={0};


    dp[n-1]=0;  //as last cell is our destination cell
    for(i=n-2;i>-1;--i){
        ans=INT_MAX;
        jumpSize=arr[i];
        if(jumpSize==0){
            dp[i]=INT_MAX;
            continue;
        }
        for(j=1;j<=jumpSize && i+j<=n-1;++j){
            ans=min(ans,dp[i+j]);
        }
        if(ans!=INT_MAX)
            dp[i]=ans+1;
        else
            dp[i]=ans;
    }
    display(dp,n);

    if(dp[0]==INT_MAX)
        return -1;
    return dp[0];
}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];
    cout<<minSteps(arr,n)<<endl;

    return 0;
}
