#include<bits/stdc++.h>
using namespace std;

void solve(int **arr,int n,int m,int x){
    int i,j,mid,l,h,row;

    //search for row
    l=0,h=n-1;

    while(l<=h){
        mid=l+(h-l)/2;
        if(x>=arr[mid][0] && x<=arr[mid][m-1])
            break;
        if(x<arr[mid][0])
            h=mid-1;
        else
            l=mid+1;
    }
    if(l>h){
        cout<<"Not found";
        return;
    }
    row=mid;

    //search for val in that row
    l=0,h=m-1;
    while(l<=h){
        mid=l+(h-l)/2;
        if(x==arr[row][mid])
            break;
        if(x>arr[row][mid])
            l=mid+1;
        else
            h=mid-1;
    }
    if(l>h){
        cout<<"Not found";
        return;
    }
    cout<<"Found at index:"<<row<<","<<mid;
}

int main(){
    int i,j,n,m,x;
    cin>>n>>m;
    int **arr=new int*[n];
    for(i=0;i<n;++i)
        arr[i]=new int[m];

    for(i=0;i<n;++i){
        for(j=0;j<m;++j)
            cin>>arr[i][j];
    }
    cout<<"Enter element to be searched:";
    cin>>x;
    solve(arr,n,m,x);
    return 0;
}
