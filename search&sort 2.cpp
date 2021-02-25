//Find a Fixed Point (Value equal to index) in a given array
#include<bits/stdc++.h>
using namespace std;

vector<int> valueEqualToIndex(int arr[], int n) {
    int i; vector<int> ans;
    for(i=0;i<n;++i){
        if(i+1==arr[i])
            ans.push_back(i+1);
    }

    return ans;
}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];
    vector<int> ans=valueEqualToIndex(arr,n);
    for(auto x:ans)
        cout<<x<<" ";
    return 0;
}
