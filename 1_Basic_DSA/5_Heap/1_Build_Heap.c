#include<stdio.h>
#include<math.h>
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int r=2*i+2;
    int l=2*i+1;
    if(l<n&&arr[l]>arr[largest])
    largest=l;

    if(r<n&&arr[r]>arr[largest])
    largest=r;

    if(i!=largest)
    {
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;

        heapify(arr,n,largest);
    }
}
void build_max_heap(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
void print(int arr[],int n)
{
    printf("HEAP:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main(){
    
    int arr[]={1,2,3,4,5,6,9};
    int size=sizeof(arr)/sizeof(int);
    build_max_heap(arr,size);
    print(arr,size);
    return 0;
}