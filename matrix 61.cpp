#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i,j,minrow,mincol,maxrow,maxcol,total,c;
    bool flag=true;
    cin>>n>>m;

    int arr[n][m];
    for(i=0;i<n;++i){
        for(j=0;j<m;++j)
            cin>>arr[i][j];
    }

    cout<<"Original\n";
    for(i=0;i<n;++i){
        for(j=0;j<m;++j)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }


    minrow=mincol=0;
    maxcol=m-1,maxrow=n-1;
    total=n*m,c=0;
    while(c<total){

        //left wall
        for(i=minrow,j=mincol ; i<=maxrow && c<total ; ++i){
            cout<<arr[i][j]<<" ";
            ++c;
        }
        ++mincol;

        //bottom wall
        for(i=maxrow,j=mincol ; j<=maxcol && c<total ; ++j){
            cout<<arr[i][j]<<" ";
            ++c;
        }
        --maxrow;

        //right wall
        for(i=maxrow,j=maxcol ; i>=minrow && c<total ; --i){
            cout<<arr[i][j]<<" ";
            ++c;
        }
        --maxcol;

        //top wall
        for(i=minrow,j=maxcol ; j>=mincol && c<total ; --j){
            cout<<arr[i][j]<<" ";
            ++c;
        }
        ++minrow;
    }

    return 0;
}
