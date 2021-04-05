//sudoku solver
#include<bits/stdc++.h>
using namespace std;

bool isValid(int **board,int x,int y,int value){
    int i,j;

    //check for row
    for(j=0;j<9;++j){
        if(board[x][j]==val)
            return false;
    }

    //check for col
    for(i=0;i<9;++i){
        if(board[i][y]==val)
            return false;
    }

    //check for submatrix of 3x3
    for(i=3*(x/3); i< 3*(x/3)+3; ++i){
        for(j=3*(y/3); j<3*(y/3)+3; ++j){
            if(board[x][y]==val)
                return false;
        }
    }
}

void displayMatrix(int **board){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

void solve(int **board,int x){
    //success condition
    if(x>=9){   //means all above rows satisfied
        displayMatrix(board);
        return;
    }
    for(int y=0;y<9;++y){
        for(int val=1;val<=9;++val){
            if(isValid(board,x,y,val)){
                board[x][y]=val;
                solve()
            }


        }
    }
}

int main(){
    int i,j;
    int **board=new int*[9];
    for(i=0;i<n;++i){
        board[i]=new int[9];
    }
    cout<<"Enter values for sudoku board, filling 0 as empty spaces:"<<endl;

    for(i=0;i<9;++i){
        for(j=0;j<9;++j)
            cin>>board[i][j];
    }
    solve()
}
