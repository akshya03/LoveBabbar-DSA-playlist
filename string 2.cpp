#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter a string:";
    string s;
    int n,i;
    cin>>s;
    n=s.size();
    i=0;
    while(i<n/2){
        if(s[i]!=s[n-i-1]){
            cout<<"Not a palindrome:"<<s;
            return 0;

        }
        ++i;
    }
    cout<<"It is a palindrome:"<<s;
    return 0;
}
