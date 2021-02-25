/*
C(n, k) = C(n-1, k-1) + C(n-1, k)
C(n, 0) = C(n, n) = 1
*/
//https://www.youtube.com/watch?v=jIb1W3ObIho&ab_channel=CodeLibrary

#include<bits/stdc++.h>
using namespace std;

int optimized(int n,int r){
    int i,mod=1000000007;
    if(r>n)
        return 0;

    int dp[r+1]={};
    for(i=1;i<=r;++i){

    }

}

int nCr(int n,int r){   //using pascals traingle
    //if(r>n)
    //    return -1;    return 0 automatically;
    int i,j,mod=1000000007;
    int dp[n+1][r+1]={};

    for(i=0;i<=n;++i)
        dp[i][0]=1;

    for(i=1;i<=n;++i){
        for(j=1;j<=r;++j){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }

    /*display matrix
    for(i=0;i<=n;++i){
        for(j=0;j<=r;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
    */
    return dp[n][r];

}

int main(){
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r)<<endl;
    return 0;
}
