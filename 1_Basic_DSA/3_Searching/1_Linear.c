#include<stdio.h>
int lsearch(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    if(key==arr[i])return i+1;
    
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(int);
    int key=15;
    int pos=lsearch(arr,size,key);
    if(pos!=-1)
    printf("ELEMENT FOUND AT %d\n",pos);
    else
    printf("ELEMENT NOT FOUND\n");
    return 0;
}