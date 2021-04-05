//search in a maze: print all paths
#include<bits/stdc++.h>
using namespace std;
#define MAX 5

bool isValid(int arr[MAX][MAX],bool **visited,int n,int x,int y){
    if(x<0 || y<0 || x>=n || y>=n || arr[x][y]==0 || visited[x][y]==1)
        return false;
    return true;
}

void solve(int arr[MAX][MAX],int n,bool **visited,vector<string> &ans,string s,int x,int y){
    if(x==n-1 && y==n-1){
        ans.push_back(s);
        return;
    }

    visited[x][y]=1;

    //check left cell
    if(isValid(arr,visited,n,x,y-1)){
        s.push_back('L');
        solve(arr,n,visited,ans,s,x,y-1);
        s.pop_back();
    }
    //check right cell
    if(isValid(arr,visited,n,x,y+1)){
        s.push_back('R');
        solve(arr,n,visited,ans,s,x,y+1);
        s.pop_back();
    }
    //check top cell
    if(isValid(arr,visited,n,x-1,y)){
        s.push_back('U');
        solve(arr,n,visited,ans,s,x-1,y);
        s.pop_back();
    }
    //check bottom cell
    if(isValid(arr,visited,n,x+1,y)){
        s.push_back('D');
        solve(arr,n,visited,ans,s,x+1,y);
        s.pop_back();
    }
    visited[x][y]=0;
}

vector<string> findPath(int arr[MAX][MAX], int n){
    string s="";
    vector<string> ans;
    if(arr[0][0]==0)    //checks if rat's start pos==0
        return ans;
    bool **visited=new bool*[n];
    for(int i=0;i<n;++i)
        visited[i]=new bool[n]();
    solve(arr,n,visited,ans,s,0,0);

    return ans;
}

int main(){
    int n;
    cout<<"Enter size of matrix(max=5):";
    cin>>n;
    int arr[MAX][MAX];
    cout<<"Enter maze:";
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>arr[i][j];

    vector<string> ans=findPath(arr,n);
    for(auto x:ans)
        cout<<x<<" ";
    return 0;

}
