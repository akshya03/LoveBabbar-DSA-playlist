//longest repeating subsequence
#include<bits/stdc++.h>
using namespace std;

void displayLRS(int **dp,int n,string s){
    int i,j;
    string ans="";

    i=j=n;
    while(i>0 && j>0){
        if(dp[i][j]==dp[i-1][j])
            --i;
        else if(dp[i][j]==dp[i][j-1])
            --j;
        else{
            //ans.insert(0,s[i-1]);
            ans=s[i-1]+ans;
            --i,--j;
        }

    }
    cout<<ans;
}

void solve(string s1){
    string s2;
    int i,j,n;

    s2=s1;
    n=s1.size();

    int **dp=new int*[n+1];
    for(i=0;i<=n;++i)
        dp[i]=new int[n+1];

    for(i=0;i<=n;++i){
        dp[0][i]=0;
        dp[i][0]=0;
    }

    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            if(s1[i-1]==s2[j-1] && i!=j)
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<<dp[n][n]<<endl;
    displayLRS(dp,n,s1);
}

int main(){
    string s1;
    cin>>s1;
    solve(s1);
    return 0;
}
