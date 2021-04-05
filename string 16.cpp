//balanced parenthesis

#include<bits/stdc++.h>
using namespace std;

bool ispar(string x){
    stack<char> stk;
    int i,j;

    for(auto ch:x){
        if(ch=='{' || ch=='(' || ch=='[')
            stk.push(ch);
        else if(ch=='}'){
            if(stk.empty() || stk.top()!='{')
                return false;
            stk.pop();
        }
        else if(ch==']'){
            if(stk.empty() || stk.top()!='[')
                return false;
            stk.pop();
        }
        else if(ch==')'){
            if(stk.empty() || stk.top()!='(')
                return false;
            stk.pop();
        }
    }
    if(!stk.empty())
        return false;
    return true;
}

int main(){
    string s;
    cin>>s;
    cout<<ispar(s)<<endl;
    return 0;
}
