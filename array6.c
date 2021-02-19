#include<stdio.h>
#include<stdlib.h>

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
    int i,j,n,*arr;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));

    for(i=0;i<n;++i)
        scanf("%d",(arr+i));

    i=0,j=n-1;
    while(i<j){
        swap((arr+i),(arr+j));
        ++i,--j;
    }
    display(arr,n);
    return 0;

}
