#include <iostream>
#include "Quicksort_Lib.h"
using namespace std;

int partition(int *arr,int left,int right)
{
    int pivot=arr[left];
    int l = left + 1;
    int r = right;
    while(r > l)
    {
        while(r >= l && arr[l] <= pivot)
        {
            l++;
        }

        while(r >= l && arr[r] >= pivot)
        {
            r--;
        }

        if (r > l)
        {
            swap(arr[l],arr[r]);
        }
    }
    swap(arr[left],arr[r]);
    return r;
}

void quickSort(int *arr,int left,int right)
{
    if(right - left <= 1)
        return ;

    int p = partition(arr,left,right);
    quickSort(arr,left,p-1);
    quickSort(arr,p+1,right);
}
