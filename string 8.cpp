//longest palindrome substring
//dynamic programming
//https://www.youtube.com/watch?v=UflHuQj6MVA&t=492s&ab_channel=TECHDOSE

#include<bits/stdc++.h>
using namespace std;

bool checkPalinBrute(string s){
    int i,j,n;
    n=s.length();

    i=0,j=n-1;
    while(i<j){
        if(s[i]!=s[j])
            return false;
        ++i,--j;
    }
    return true;
}

void checkPalin(string s){
    int n,i,j,k,ansIndex,ansLen;

    n=s.length();
    bool dp[n][n]={};   //rows=start index, cols= end index

    //preprocessing
    for(i=0;i<n;++i)
        dp[i][i]=1; //diagonal has only 1 element =>palindrome yes
    ansIndex=0,ansLen=1;


    for(i=0;i<n-1;++i){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            if(ansLen==1){  //as we want 1st longest substring
                ansLen=2, ansIndex=i;
            }
        }

    }

    //move diagonally
    for(k=3;k<=n;++k){  //preprocessed for substring length=2
        //fixing the start index of substring
        for(i=0;i<n-k+1;++i){
            j=i+k-1;    //calc ending index o substring
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
                if(k>ansLen){
                    ansLen=j-i+1, ansIndex=i;
                }
            }
        }
    }




    //display matrix
    cout<<"  ";
    for(i=0;i<n;++i)
        cout<<s[i]<<" ";
    cout<<endl;
    for(i=0;i<n;++i){
        cout<<s[i]<<" ";
        for(j=0;j<n;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    cout<<s.substr(ansIndex,ansLen)<<endl;
}

int main(){
    string s,temp;
    int i,j,n;

    cin>>s;
    n=s.length();

    /*  //brute force
    for(i=0;i<n;++i){
        for(j=i;j<n;++j){
            temp=s.substr(i,j-i+1);
            if(checkPalinBrute(temp))
                cout<<temp<<endl;
        }
    }
    */

    checkPalin(s);
    return 0;
}
