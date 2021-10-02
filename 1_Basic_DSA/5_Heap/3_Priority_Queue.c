#include <stdio.h>
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int r = 2 * i + 2;
    int l = 2 * i + 1;
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (i != largest)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr, n, largest);
    }
}
void insertion_heapify(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0)
    {
        if (arr[i] > arr[parent])
        {
            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;
            insertion_heapify(arr, n, parent);
        }
    }
}
void build_max_heap(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
void insert(int arr[], int *n, int key)
{
    *n = *n + 1;
    arr[*n - 1] = key;
    insertion_heapify(arr, *n, *n - 1);
}
void delete_root(int arr[], int *n)
{
    int last = arr[*n - 1];
    arr[0] = last;
    *n = *n - 1;
    heapify(arr, *n, 0);
}
void print(int arr[], int n)
{
    printf("HEAP:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[100];
    for (int i = 0; i < 100; i++)
        arr[i] = 0;

    int size = 0;
    int inp;
    do
    {
        printf("OPERATIONS:\n0)QUIT\n1)INSERT\n2)MAX\n3)EXTRACT_MAX\n4)PRINT\n5)INCREASE KEY\n");
        printf("ENTER YOUR CHOICE:");
        scanf("%d", &inp);
        switch (inp)
        {
        case 1:
            printf("ENTER THE DATA TO ENTER:");
            int data;
            scanf("%d", &data);
            insert(arr, &size, data);
            break;
        case 2:
            printf("MAX:%d\n", arr[0]);
            break;
        case 3:
            printf("REMOVING MAX:%d\n", arr[0]);
            delete_root(arr, &size);
            break;
        case 4:
            print(arr, size);
            break;
        case 5:
            printf("ENTER I AND K:");
            int i,k;
            scanf("%d%d",&i,&k);
            if(i<size)
            {
                arr[i]+=k;
                insertion_heapify(arr,size,i);
                print(arr,size);
            }
            else
            printf("I IS GREATER THAN THE SIZE\n");
        }
    } while (inp != 0);

    return 0;
}