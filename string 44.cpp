#include<bits/stdc++.h>
using namespace std;

void printAllSubstrings(string s){
    int i,j,n;
    n=s.size();
    for(i=0;i<n;++i){
        for(j=1;j<=n-i;++j)
            cout<<s.substr(i,j)<<endl;
    }
}

int main(){
    string s;
    cin>>s;
    printAllSubstrings(s);


    return 0;
}
