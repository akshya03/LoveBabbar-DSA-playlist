#include<bits/stdc++.h>
using namespace std;

void dfsOfGraph(int V,vector<int> adj[]){
    int u;
    stack<int> stk;
    bool visited[V]={};

    stk.push(0);
    visited[0]=1;
    while(!stk.empty()){
        u=stk.top();
        stk.pop();
        cout<<u<<" ";
        for(int v:adj[u]){
            if(!visited[v]){
                visited[v]=1;
                stk.push(v);
            }
        }
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<int>adj[V];
    for(int i=0;i<E;++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    dfsOfGraph(V,adj);
    return 0;
}
/*
5 4
0 1
0 2
0 3
2 4
*/
