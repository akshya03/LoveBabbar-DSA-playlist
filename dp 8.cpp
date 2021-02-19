//https://www.youtube.com/watch?v=_gPcYovP7wc&ab_channel=AdityaVerma
#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,n,k;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];

    bool dp[n+1][k+1];
    for(j=0;j<=k;++j)
        dp[0][j]=false;
    for(i=0;i<=n;++i)
        dp[i][0]=true;
    sort(arr,arr+n);

    for(i=1;i<=n;++i){

        for(j=1;j<=k;++j){

            if(arr[i-1]<=j){
                dp[i][j]= (dp[i-1][j-arr[i-1]]) || (dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][k]<<endl;

    //printing dp
    for(i=0;i<=n;++i){
        for(j=0;j<=k;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    //printing the subset

    vector <int> ans,leftout;
    vector<int> ::iterator itr;
    i=n,j=k;
    while(i>0 && j>0){
        cout<<i<<" "<<j<<endl;
        if(dp[i-1][j]==0){
            ans.push_back(arr[i-1]);

            j=j-arr[i-1];
            --i;
        }
        else{
            leftout.push_back(arr[i-1]);
            --i;
        }

    }
    cout<<i<<" "<<j<<endl;
    for(itr=ans.begin();itr<ans.end();++itr)
        cout<<*itr<<" ";
        cout<<endl;
    for(itr=leftout.begin();itr<leftout.end();++itr)
        cout<<*itr<<" ";
    return 0;
}
