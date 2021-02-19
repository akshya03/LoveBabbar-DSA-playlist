#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value,weight;
};
struct ItemModified{
    int weight;
    double val;
};

bool comp(ItemModified a,ItemModified b){
    return a.val>b.val;
}

double solve(int W,Item arr[],int n){

    int i;
    double currCap,currVal,x;

    ItemModified arr2[n];
    for(i=0;i<n;++i){
        arr2[i].weight=arr[i].weight;
        arr2[i].val=(double)arr[i].value/(double)arr[i].weight;
    }
    sort(arr2,arr2+n,comp);


    currVal=currCap=i=0;
    while(i<n && currCap<W){
        if(arr2[i].weight+currCap<=W)
            x=arr2[i].weight;
        else
            x=W-currCap;
        cout<<"Item weight="<<arr2[i].weight<<"\tWeight selected="<<x<<"\tValue per weight="<<arr2[i].val<<endl;
        currCap+=x;
        currVal+=x*arr2[i].val;
        ++i;
    }
    return currVal;
}

int main(){
    int n,W,i;
    cin>>n>>W;
    Item arr[n];
    for(i=0;i<n;++i)
        cin>>arr[i].value>>arr[i].weight;
    cout<<solve(W,arr,n);
    return 0;

}
