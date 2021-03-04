//find union and intersection of 2 sorted arrays
//merge sort logic used
#include<bits/stdc++.h>
using namespace std;

void display_union_and_intersection(int *arr1,int n1,int *arr2,int n2){
    vector<int> ans1,ans2;
    int i,j;
    i=j=0;
    while(i<n1 && j<n2){
        if(arr1[i]==arr2[j]){
            ans1.push_back(arr1[i]);
            ans2.push_back(arr1[i]);
            ++i,++j;
        }
        else if(arr1[i]<arr2[j])
            ans1.push_back(arr1[i++]);
        else
            ans1.push_back(arr2[j++]);
    }
    while(i<n1)
        ans1.push_back(arr1[i++]);
    while(j<n2)
        ans1.push_back(arr2[j++]);

    cout<<"Union:";
    for(int x:ans1)
        cout<<x<<" ";

    cout<<"\nIntersection:";
    for(int x:ans2)
        cout<<x<<" ";
    cout<<endl;
}

int main(){
    int i,n1,n2;
    cout<<"Enter size and elements of 1st array:";
    cin>>n1;
    int arr1[n1];
    for(i=0;i<n1;++i)
        cin>>arr1[i];
    cout<<"Enter size and elements of 2nd array:";
    cin>>n2;
    int arr2[n2];
    for(i=0;i<n2;++i)
        cin>>arr2[i];
    display_union_and_intersection(arr1,n1,arr2,n2);
    //display_intersection(arr1,n1,arr2,n2);
}
