//bfs of directed graph, input by adjacency list
#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V,vector<int> adj[]){
    int u;
    bool included[V]={};    //used to prevent cycles
    vector<int> ans;
    queue<int> que;

    que.push(0);
    included[0]=1;  //starting from node 0
    while(!que.empty()){
        u=que.front();
        que.pop();
        ans.push_back(u);
        for(int v:adj[u]){
            if(included[v]==0){     //not included yet in ans
                included[v]=1;
                que.push(v);
            }
        }
    }
    return ans;
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
    vector<int> ans=bfsOfGraph(V,adj);
    for(int x:ans)
        cout<<x<<" ";
}
/*
5 4
0 1
0 2
0 3
2 4
ans:0 1 2 3 4
*/
