#include<bits/stdc++.h>
using namespace std;

void displayMatrix(int **solMatrix,int n,int m){
    int i,j;
    cout<<endl;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j)
            cout<<solMatrix[i][j]<<" ";
        cout<<endl;
    }

}

bool isValid(int **maze,int n,int m,int **solMatrix,int x,int y){
    if(x>=n || x<0 || y>=m || y<0 || maze[x][y]==0 || solMatrix[x][y]==1)
        return false;
    return true;

}


//returns all sol matrices
void mazeHelp(int **maze,int n,int m,int **solMatrix,int x,int y){

    if(x==n-1 && y==m-1){
        solMatrix[x][y]=1;
        displayMatrix(solMatrix,n,m);
        return;
    }


    if(!(isValid(maze,n,m,solMatrix,x,y)))
        return;

    solMatrix[x][y]=1;
    mazeHelp(maze,n,m,solMatrix,x-1,y); //up
    mazeHelp(maze,n,m,solMatrix,x+1,y); //down
    mazeHelp(maze,n,m,solMatrix,x,y-1); //left
    mazeHelp(maze,n,m,solMatrix,x,y+1); //right
    solMatrix[x][y]=0;
}

void ratInAMaze(int **maze,int n,int m){
    //displayMatrix(maze,n,m);
    int i,j;

    int **solMatrix=new int*[n];
    for(i=0;i<n;++i){
        solMatrix[i]=new int[m];
        for(j=0;j<m;++j)
            solMatrix[i][j]=0;
    }
    //displayMatrix(solMatrix,n,m);
    mazeHelp(maze,n,m,solMatrix,0,0);


}


int main(){
    int n,m,i,j;
    cin>>n>>m;
    int **maze=new int*[n];
    for(i=0;i<n;++i)
        maze[i]=new int[m];

    for(i=0;i<n;++i){
        for(j=0;j<m;++j)
            cin>>maze[i][j];
    }
    ratInAMaze(maze,n,m);
    return 0;

}

/*
5 5
1 0 0 0 0
1 1 1 1 1
1 1 1 0 1
0 0 0 0 1
0 0 0 0 1
*/
