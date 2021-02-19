#include<bits/stdc++.h>
using namespace std;


int main(){
    int i,l;
    char str[100];
    cin>>str;
    getchar();  //clear '\n' in Input buffer
    l=strlen(str);

    for(i=0;i<l/2;++i)
        swap(str[i],str[l-i-1]);
    cout<<str;

    return 0;
}
