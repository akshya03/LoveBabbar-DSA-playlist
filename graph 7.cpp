//minimum steps by knight
//bfs

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector< vector<int> > &board,int x,int y,int n,vector<int>&KnightPos){
    if(x<0 || y<0 || x>=n || y>=n || board[x][y]!=0 || (x==KnightPos[0] && y==KnightPos[1])) //
        return false;
    return true;
}

void display(vector< vector<int> > &board, int n){
    for(auto row: board){
        for(auto val: row)
            cout<<val<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n, vector<pair<int,int>> &temp){

    --KnightPos[0],--KnightPos[1],--TargetPos[0],--TargetPos[1];    //for 1 based indexing
    vector<pair<int,int>> moves;    //all possible moves
    moves.push_back(make_pair(1,2));
    moves.push_back(make_pair(2,1));
    moves.push_back(make_pair(2,-1));
    moves.push_back(make_pair(1,-2));
    moves.push_back(make_pair(-1,-2));
    moves.push_back(make_pair(-2,-1));
    moves.push_back(make_pair(-2,1));
    moves.push_back(make_pair(-1,2));

    int x,y,c,i;
    vector<vector<int>> board(n,vector<int> (n,0));
    queue<pair<int,int>> que;

    pair<int,int> curr;

    x=KnightPos[0], y=KnightPos[1];

    que.push(make_pair(x,y));
    temp.push_back(make_pair(x,y));
    board[x][y]=0;

    while(!que.empty()){
        //cout<<"Size of queue: "<<que.size()<<endl;
        //display(board,n);
        curr=que.front();
        que.pop();

        x=curr.first, y=curr.second;
        if(x==TargetPos[0] && y==TargetPos[1]){
            display(board,n);
            return board[x][y];
        }

        //cout<<"Current: "<<curr.first<<" "<<curr.second<<endl;
        for(i=0;i<8;++i){
            if(isValid(board, x+moves[i].first, y+moves[i].second, n, KnightPos)){
                //cout<<"Found at: "<<x+moves[i].first<<" "<< y+moves[i].second<<endl;
                board[x+moves[i].first][y+moves[i].second] = board[x][y]+1;
                que.push(make_pair(x+moves[i].first, y+moves[i].second));
                //cout<<"Add to queue:"<<x+moves[i].first<< y+moves[i].second<<endl;
                temp.push_back(make_pair(x+moves[i].first, y+moves[i].second));
                //display(board,n);
                //cout<<"Size of queue2: "<<que.size()<<endl;
            }
        }

    }

    return -1;
}

int main(){
    vector<int> KnightPos(2),TargetPos(2);
    int n;
    //cout<<"Enter size of board:";
    cin>>n;
    //cout<<"Enter Knight position:";
    cin>>KnightPos[0]>>KnightPos[1];
    //cout<<"Enter Target position:";
    cin>>TargetPos[0]>>TargetPos[1];
    vector<pair<int,int>> temp;

    cout<<minStepToReachTarget(KnightPos,TargetPos,n,temp)<<endl;
    /*
    for(auto x: temp){
        cout<<x.first<<" "<<x.second<<endl;
    }
    */
    return 0;
}
