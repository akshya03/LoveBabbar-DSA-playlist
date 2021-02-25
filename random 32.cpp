#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &arr,int x,int y,int a,int b){
    if(x<0 || y<0 || x>a || y>b)
        return false;
    return true;
}

int solve(vector<vector<int>> &arr,int x,int y,int a,int b){
    static int c=0;
    if(x==a && y==b){
        ++c;

    }
    //right
    arr[x][y]=1;
    if(isValid(arr,x,y+1,a,b))
        solve(arr,x,y+1,a,b);
    //down
    if(isValid(arr,x+1,y,a,b))
        solve(arr,x+1,y,a,b);
    arr[x][y]=0;
    return c;
}

int NumberOfPath(int a, int b) {
    //code here

    vector<vector<int>> arr(a,vector<int>(b,0));
    //arr[0][0]=1;
    return solve(arr,0,0,a-1,b-1);

}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<NumberOfPath(a,b);
    return 0;
}
