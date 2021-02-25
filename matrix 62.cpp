//https://www.youtube.com/watch?v=ZYpYur0znng&t=344s&ab_channel=takeUforward
//prob where val[i][m-1]<=val[i+1][0]
#include<bits/stdc++.h>
using namespace std;

void solve2BinarySearch(int **arr,int n,int m,int x){
    int mid,l,h,row;

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
    cout<<"Method 1,Found at index:"<<row<<","<<mid<<endl;
}

void solveUsing1BinarySearch(int **arr,int n,int m,int x){
    //low high using imaginary indexes
    //assume given 2d array as 1d sorted array(0,n*m-1)
    //compute rowIndex, colIndex from imaginary 1d array to equivalent 2d array
    int l,h,mid,rowIndex,colIndex;
    l=0,h=m*n-1;

    while(l<=h){
        mid=l+(h-l)/2;
        rowIndex=mid/m; //divided by total cols (or no. of values in 1 row)
        colIndex=mid%m;
        if(arr[rowIndex][colIndex]==x)
            break;
        if(x<arr[rowIndex][colIndex])
            h=mid-1;
        else
            l=mid+1;
    }
    if(l>h){
        cout<<"Not found";
        return;
    }
    cout<<"Method 2,Found at index:"<<rowIndex<<","<<colIndex<<endl;
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
    solve2BinarySearch(arr,n,m,x);
    solveUsing1BinarySearch(arr,n,m,x);
    return 0;
}
