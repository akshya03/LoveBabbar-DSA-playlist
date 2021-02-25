#include<bits/stdc++.h>
using namespace std;

void solve(string S){
    int i,n;
    n=S.size();

    unordered_map<char,int> umap;
    for(i=0;i<n;++i){
        ++umap[S[i]];
    }

    for(auto x: umap){
        if(x.second>1)
            cout<<x.first<<":"<<x.second<<endl;
    }
}

int main(){
    string s;
    //cin>>s;
    getline(cin,s);
    solve(s);
    return 0;
}
