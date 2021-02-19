//job sequencing greedy
#include<bits/stdc++.h>
using namespace std;

typedef struct job{
    char name;
    int dead,profit;
}Job;

bool comp(Job x,Job y){
    if(x.profit>y.profit)
        return true;
    return false;
}

pair<int,int> solve(Job arr[],int n){
    // your code here
    sort(arr,arr+n,comp);
    unordered_set<int> uset;
    int i,j,max_profit,curr_dead,curr_profit;

    max_profit=0;
    for(i=0;i<n;++i){
        curr_dead=arr[i].dead;
        while(curr_dead>0 && uset.find(curr_dead)!=uset.end())
            --curr_dead;
        if(curr_dead>0){
            uset.insert(curr_dead);
            max_profit+=arr[i].profit;
        }
    }
    pair<int,int> ans;
    ans.first=uset.size();
    ans.second=max_profit;
    return ans;
}

int main(){
    int n,i;
    cin>>n;
    Job arr[n];
    for(i=0;i<n;++i){
        cin>>arr.name>>arr.dead>>arr.profit;
    }
    solve(arr,n);
}
