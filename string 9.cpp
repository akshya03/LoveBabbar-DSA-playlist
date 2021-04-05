#include<bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str){
    int n,i,j;
    n=str.length();

    int dp[n+1][n+1]={};

    for(i=0;i<=n;++i){
        dp[i][0]=0;
        dp[0][i]=0;
    }

    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            if(str[i-1]==str[j-1] && i!=j)
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string ans="";
    i=j=n;
    while(i>0 && j>0){
        if(dp[i][j]==dp[i-1][j])
            --i;
        else if(dp[i][j]==dp[i][j-1])
            --j;
        else{
            ans=str[i-1]+ans;
            --i,--j;
        }
    }

    for(i=0;i<=n;++i){
        for(j=0;j<=n;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<ans<<endl;
    return ans.length();
}

int main(){
    string s;
    cin>>s;
    cout<<LongestRepeatingSubsequence(s)<<endl;
    return 0;
}
