//edit distance dp
//same no. of operations to convert a->b or b->a
//https://www.youtube.com/watch?v=Ti9CByuukE8&ab_channel=KeertiPurswani
//TOP TO BOTTOM=delete from s1
//left to right=insert into s1
//diagonal=same element or replace
#include<bits/stdc++.h>
using namespace std;

void displayMatrix(int **solMatrix,int n,int m){
    int i,j;
    cout<<endl;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j)
            cout<<solMatrix[i][j]<<" ";
        cout<<endl;
    }

}

void solve(string s1,string s2){
    //converting s1 to s2
    int n1,n2,i,j;
    n1=s1.size();
    n2=s2.size();

    //int dp[n1+1][n2+1];
    int **dp=new int*[n1+1];
    for(i=0;i<=n1;++i)
        dp[i]=new int[n2+1];

    //insert each char into s1(len=0) to make s2
    for(j=0;j<=n2;++j)
        dp[0][j]=j;

    //delete each char from s1 to make s2(len=0)
    for(i=1;i<=n1;++i)
        dp[i][0]=i;

    for(i=1;i<=n1;++i){
        for(j=1;j<=n2;++j){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min( dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1]) )+1;
            }
        }
    }
    cout<<dp[n1][n2]<<endl;
    displayMatrix(dp,n1+1,n2+1);
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    solve(s1,s2);
    return 0;
}
