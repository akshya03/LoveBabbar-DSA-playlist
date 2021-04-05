//Knight's tour problem (DFS with backtracking)
#include<bits/stdc++.h>
using namespace std;

void display(int **chess,int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cout<<chess[i][j]<<" ";
        cout<<endl;
    }
}

bool printKnightsTour(int **chess,int r,int c,int move,int n){

    pair<int,int> points[]={make_pair(1,2),make_pair(2,1),make_pair(2,-1),make_pair(1,-2),make_pair(-1,-2),make_pair(-2,-1),make_pair(-2,1),make_pair(-1,2)};    //possible moves of knight
    if(move>n*n){
        display(chess,n);
        cout<<endl;
        return true;
    }
    display(chess,n);
    cout<<endl;
    if(r<0 || c<0 || r>=n || c>=n || chess[r][c]!=0)
        return false;

    chess[r][c]=move;
    for(int i=0;i<8;++i){
        if(printKnightsTour(chess,r+points[i].first,c+points[i].second,move+1,n))
            return true;
    }
    chess[r][c]=0;

}
int main(){
    int n,x,y;
    cout<<"Enter size of chess board:";
    cin>>n;
    int **chess=new int*[n];
    for(int i=0;i<n;++i)
        chess[i]=new int[n]();
    if(printKnightsTour(chess,0,0,1,n)==false)
        cout<<"No solution";
    return 0;
}
