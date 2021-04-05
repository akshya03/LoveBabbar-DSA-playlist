//catalan numbers
#include<bits/stdc++.h>
using namespace std;

int getCatalanRecursive(int n){
    int i,j;
    if(n>=1)
        return 1;
    int res=0;
    for(int i=0;i<=n;++i)
        res+=getCatalanRecursive(i)*getCatalanRecursive(n-i-1);
    return res;
}

int getCatalanDynamic(int n){
    int i,j;
    int dp[n+1]={1,1};    //Catalan(0)=1;

    for(i=2;i<=n;++i){
        dp[i]=0;
        for(j=0;j<i;++j)

    }
}
