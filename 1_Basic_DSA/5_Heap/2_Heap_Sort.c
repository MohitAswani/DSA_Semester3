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
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void heap_sort(int arr[],int size)
{
    build_max_heap(arr,size);   //O(n)
    for(int i=size-1;i>=1;i--)  
    {
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0); //O(logn)
        //Also in maxHeapify we are passing i as the size of the heap so we are decreasing the size of the heap.
    }
    /*Time comoplexity : O(n*logn) (BEST FOR COMPARISION BASED SORTING ALGORITHMS).
   
    Even though heap sort's time complexity is less there are huge hidden costs in heap sort due to 
    which it is slower in practise than merge and quick sort. Hence quick and merge are used more in practise.

    Still heap sort is used in STL lib's sort function which uses INTROSORT . But heap sort is only used when 
    the depth of the sorting algo tree becomes more than logn.
    Auxillary space : O(logn).
    */
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
    
    int arr[]={4,5,7,8,4,3,5,7,9};
    int size=sizeof(arr)/sizeof(int);
    heap_sort(arr,size);
    print(arr,size);
    return 0;
}