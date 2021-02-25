//check if str2 is rotation of str1
//x is substring of y: index i=isSubstring(x,y)
#include<bits/stdc++.h>
using namespace std;

void solve(string s1,string s2){
    int n1,n2,f;
    string temp;
    n1=s1.size();
    n2=s2.size();

    if(n1!=n2){
        cout<<"Not a rotation";
        return;
    }

    temp=s1+s1;
    f=temp.find(s2);
    //if(f==-1)     //same as npos: static const size_t npos = -1;
    if(f==string::npos)
        cout<<"Not a rotation";
    else
        cout<<"It is a rotation from index:"<<f;
}

int main(){
    string S1,S2;
    getline(cin,S1);
    getline(cin,S2);

    solve(S1,S2);
    return 0;
}
