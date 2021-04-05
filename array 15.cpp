//Minimum no. of Jumps to reach end of an array
#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
    int i,jumpSize,ans,j;
    int dp[n+1]={};

    dp[n-1]=0;  //last cell is destination cell
    for(i=n-2;i>0;--i){
        jumpSize=arr[i];
        ans=INT_MAX;

        if(jumpSize==0){
            dp[i]=INT_MAX;
            continue;
        }

        for(j=1;j<=jumpSize && i+j<=n-1;++j){   //n-1 is index of last cell
            ans=min(ans,dp[i+j]);
        }
        if(ans==INT_MAX)
            dp[i]=ans;
        else
            dp[i]=ans+1;
    }
    return dp[0]==INT_MAX?-1:dp[0];
}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];
    cout<<minJumps(arr,n)<<"=min jumps required";
    return 0;
}
