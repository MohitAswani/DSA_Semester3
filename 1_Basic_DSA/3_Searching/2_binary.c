#include <stdio.h>
int bsearch(int arr[], int beg, int end, int key)
{
    int mid=0;
    while (beg <=end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == key)
            return mid+1;
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            beg = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1,11,16,57,89,455,69420};
    int size = sizeof(arr) / sizeof(int);
    int key = 1;
    int pos = bsearch(arr, 0, size, key);
    if (pos != -1)
        printf("ELEMENT FOUND AT %d\n", pos);
    else
        printf("ELEMENT NOT FOUND\n");
    return 0;
}