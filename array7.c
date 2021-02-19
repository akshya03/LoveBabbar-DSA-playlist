#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

void swap(int *a,int *b){
    int x=*a;
    *a=*b;
    *b=x;
}

void display(int *arr,int n){
    for(int i=0;i<n;++i)
        printf("%d ",*(arr+i));
    printf("\n");
}

int main(){
    int i,j,n,*arr,s,l;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;++i)
        scanf("%d",(arr+i));

    s=INT_MAX,l=INT_MIN;
    for(i=0;i<n;++i){
        s=min(s,arr[i]);
        l=max(l,arr[i]);
    }

    display(arr,n);
    printf("Min= %d Max=%d",s,l);

    return 0;

}
