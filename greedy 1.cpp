#include<bits/stdc++.h>
using namespace std;

typedef struct activity{
    int start,finish;
}Act;

bool comp(Act a,Act b){
    return a.finish<b.finish;
}

int maxMeetings(int *,int *,int);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i,j;
        cin>>n;
        int start[n],end[n];
        for(i=0;i<n;++i)
            cin>>start[i];
        for(i=0;i<n;++i)
            cin>>end[i];
        int ans=maxMeetings(start,end,n);
        cout<<ans<<endl;
    }
    return 0;
}

int maxMeetings(int *strt,int *end,int n){
    int i,j,c;
    if(n==0)
        return 0;
    Act arr[n];
    for(i=0;i<n;++i){
        arr[i].start=strt[i];
        arr[i].finish=end[i];
    }
    sort(arr,arr+n,comp);

    c=1;
    i=0;    //first activity always selected
    for(j=1;j<n;++j){
        if(arr[j].start>arr[i].finish){
            ++c;
            i=j;    //last selected activity
        }

    }
    return c;
}
