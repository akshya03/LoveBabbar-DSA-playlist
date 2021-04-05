//n-queens problem
//prints all solutions
#include<bits/stdc++.h>
using namespace std;

void displayMatrix(const vector<vector<int>> &matrix){
    int rows,cols,i,j;
    rows=matrix.size();
    cols=matrix[0].size();
    for(i=0;i<rows;++i){
        for(j=0;j<cols;++j)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

void displayResult(const vector<vector<int>> &board,int n){
    int i,j;
    static int k=1;
    cout<<"Solution"<<k++<<endl;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            //if(board[i][j])
            //    cout<<i<<","<<j<<endl;
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<endl;
}

bool isValid(const vector<vector<int>> &board,int row,int col,int n){
    //check for queen in pos row,col with other queens
    //do not need to check row as we put 1 queen in each row
    //do not need to check below the queen row as queens are filled form top to bottom (row - to row n-1)
    int i,j;
    //check col
    for(i=row-1,j=col;i>-1;--i){
        if(board[i][j])
            return false;
    }
    //top left corner diagonal
    for(i=row-1,j=col-1;i>-1 && j>-1;--i,--j){
        if(board[i][j])
            return false;
    }
    //top right corner diagonal
    for(i=row-1,j=col+1;i>-1 && j<n;--i,++j){
        if(board[i][j])
            return false;
    }
    return true;
}

//each queenIndex corresponds to row no. (queen 0 in row 0.......)
//row=queenIndex
void helper(vector<vector<int>> &board,int n,int row){
    if(row==n){         //when row=n that means all cases for row<n have passed
        displayResult(board,n);
        return;
    }

    for(int col=0;col<n;++col){
        //checking if current place is valid, if valid set it to 1 and move to next row(queen)
        if(isValid(board,row,col,n)){
            board[row][col]=1;
            helper(board,n,row+1);
            board[row][col]=0;
        }
    }
}

void solve(int n){

    vector<vector<int>> board(n,vector<int> (n,0));

    //sending initial row index as 0
    helper(board,n,0);
}

int main(){
    int n;
    cout<<"Enter size of chess board:";
    cin>>n;
    solve(n);
    return 0;
}
