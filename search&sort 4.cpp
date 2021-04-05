//part 1: return floor(sqrt(n))

#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int n){
    long long l,r,ans,mid=0;
    l=0,r=n;
    while(l<=r){

        mid=(l+r)/2;
        //cout<<l<<" "<<r<<" "<<mid<<endl;
        if(mid*mid==n)
            return mid;
        if(mid*mid>n){
            r=mid-1;

        }
        else
            l=mid+1,ans=mid;
    }
    return ans;
}

double precSqrt(int n,int precision){
    double ans,incFrac;
    int i,j;
    incFrac=0.1;
    ans=floorSqrt(n);

    for(i=0;i<precision;++i){
        while(ans*ans<=n){
            ans+=incFrac;
        }
        ans-=incFrac;
        incFrac/=10;
    }
    return ans;
}
int main(){
    long long n,p;
    cout<<"Enter no. and decimal precision:";
    cin>>n>>p;
    cout<<floorSqrt(n)<<endl;
    cout<<precSqrt(n,p)<<endl;
    return 0;
}
