#include<bits/stdc++.h>
using namespace std;

int lcs(int n1,int n2,string s1,string s2){
    int i,j;
    int dp[n1+1][n2+1];

    for(i=0;i<=n1;++i)
        dp[i][0]=0;
    for(j=0;j<=n2;++j)
        dp[0][j]=0;

    for(i=1;i<=n1;++i){
        for(j=1;j<=n2;++j){

            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}

int main(){
    string s1,s2;
    int n1,n2;
    cin>>s1>>s2;
    n1=s1.size();
    n2=s2.size();
    cout<<lcs(n1,n2,s1,s2);
    return 0;
}
