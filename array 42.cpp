//no. of recycled pairs in an array
#include<bits/stdc++.h>
using namespace std;

void generateRotations(vector<int>&rotations,int n){
    //performing left rotation 123 231 312
    int i,k,firstDigit,powTen,x;
    rotations.clear();
    //k=no of rotations=no. of digits-1
    k=log10(n);
    powTen=(int)(pow(10,k)+0.5);
    for(i=0;i<k;++i){
        firstDigit=n/powTen;
        n=(n*10+firstDigit);
        n=n-(firstDigit*powTen*10);
        rotations.push_back(n);
    }
}

void solve(int *arr,int n){
    int i,j,ans,c;

    unordered_set<int> uset;
    unordered_set<int>:: iterator itr,itr1;
    vector<int> rotations;

    for(i=0;i<n;++i)
        uset.insert(arr[i]);
    ans=0;
    for(itr=uset.begin();itr!=uset.end();){
        generateRotations(rotations,*itr);
        for(auto x:rotations){
            if(uset.find(x)!=uset.end())
                ++ans;

        }
        itr1=itr;
        ++itr;
        uset.erase(itr1);

    }
    cout<<ans<<endl;

}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i];
    solve(arr,n);

    return 0;
}
