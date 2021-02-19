#include<bits/stdc++.h>
using namespace std;

void display(int *arr,int n){
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void solve(int arr[],int m ,int n){
    int i,j;
    int dp[n+1]={1};
    sort(arr,arr+m);

    for(i=0;i<m;++i){
        for(j=1;j<=n;++j){
            if(j-arr[i]>-1)
                //++dp[j];
                dp[j]+=dp[j-arr[i]];
        }
        //display(dp,n+1);
    }
    cout<<"Total possible ways="<<dp[n]<<endl;
}

int main(){
    int n,m,i;
    cin>>n>>m;
    int arr[m];
    for(i=0;i<m;++i)
        cin>>arr[i];
    solve(arr,m,n);
}
