//dijkastra algo-  single source shortest path
//adjacency matrix used, input as edges values
// undirected graph used here
#include<bits/stdc++.h>
using namespace std;

//returns the unvisited vertex index with min dist from src
int findMinVertex(int *distance,bool *visited,int V){
    int i,minVertex=-1;
    for(i=0;i<V;++i){
        if(visited[i]==false && (minVertex==-1 || distance[i]<minVertex))
            minVertex=i;
    }
    return minVertex;
}

void dijkstra(int **edges,int V){
    int i,j,minVertex;

    int distance[V];
    bool visited[V];

    //initialization: distance= infinity, no nodes are visited yet
    for(i=0;i<V;++i){
        distance[i]=INT_MAX;
        visited[i]=false;
    }

    distance[0]=0;
    for(i=1;i<V;++i){   //started form i=1 as src node dist already fixed at 0
        minVertex=findMinVertex(distance,visited,V);
        visited[minVertex]=1;
        for(j=0;j<V;++j){
            if(edges[minVertex][j]!=0 && edges[minVertex][j]+distance[minVertex]<distance[j]){
                distance[j]=edges[minVertex][j]+distance[minVertex];
            }
        }
    }
    for(i=0;i<V;++i)
        cout<<i<<"-"<<distance[i]<<endl;

}

int main(){
    int V,E,i,j,u,v,w;
    cout<<"Enter no. of vertices and edges:";
    cin>>V>>E;
    int **edges=new int*[V];
    for(i=0;i<V;++i)
        edges[i]=new int[V]();

    cout<<"Enter edges as u,v,w:"<<endl;
    for(i=0;i<E;++i){
        cin>>u>>v>>w;
        edges[u][v]=edges[v][u]=w;
    }

    /* //display input matrix
    for(i=0;i<V;++i){
        for(j=0;j<V;++j)
            cout<<edges[i][j]<<" ";
        cout<<endl;
    }
    */
    dijkstra(edges,V);
    return 0;

}
/*
5 7
0 1 4
0 2 8
1 3 5
1 2 2
2 3 5
2 4 9
3 4 4

ans:
0-0
1-4
2-6
3-9
4-13
*/
