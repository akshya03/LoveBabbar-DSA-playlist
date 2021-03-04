#include<bits/stdc++.h>
using namespace std;

struct Item{
    int wt,val;
};

bool comp(Item a,Item b){
    return (a.wt<b.wt);
}
int knapSack(int W, int wt[], int val[], int n)
{
   // Your code here
   Item items[n];
   int i,j;

   for(i=0;i<n;++i){
        items[i].wt=wt[i];
        items[i].val=val[i];
   }
   sort(items,items+n,comp);

   vector<vector<int>> dp(n+1,vector<int> (W+1,0));

   for(i=1;i<=n;++i){

    for(j=1;j<=W;++j){
        if(items[i-1].wt<=j){
            dp[i][j]=max(dp[i-1][j-items[i-1].wt]+items[i-1].val,dp[i-1][j]);
        }
        else
            dp[i][j]=dp[i-1][j];
    }
   }
   for(i=0;i<=n;++i){
    for(j=0;j<=W;++j)
        cout<<dp[i][j]<<" ";
    cout<<endl;h
   }
   return dp[n][W];
}

int main(){

    int n,W;
    cin>>n>>W;
    int val[n],wt[n];
    for(int i=0;i<n;++i)
        cin>>val[i];
    for(int i=0;i<n;++i)
        cin>>wt[i];
    cout<<knapSack(W,wt,val,n)<<endl;
    return 0;
}
