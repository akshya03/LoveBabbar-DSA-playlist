//merge 2 sorted arrays without using extra space
#include<bits/stdc++.h>

using namespace std;

void mergeInsertionSort(int arr1[], int arr2[], int n, int m){
    int i,j,k;

    for()
}

int main(){
    int n1,n2,i;
    cout<<"Enter size and elements of 1st array:";
    cin>>n1;
    int arr1[n1];
    for(i=0;i<n1;++i)
        cin>>arr1[i];
    cout<<"Enter size and elements of 2nd array:";
    cin>>n2;
    int arr[n2];
    for(i=0;i<n2;++i)
        cin>>arr2[i];

    mergeInsertionSort(arr1,arr2,n1,n2);

    for(i=0;i<n1;++i)
        cout<<arr1[i]<<" ";
    cout<<endl;
    for(i=0;i<n2;++i)
        cout<<arr2[i]<<" ";
    return 0;

}
