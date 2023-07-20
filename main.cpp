#include "Heapsort.h"
#include "Mergesort.h"
#include "Quicksort.h"
#include "InsertionSort.h"
#include "Hybridsort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void hybrid(int *arr, int n)
{
    if(n<70)
    {
     insertionSort(arr,n);
    }
    else
    {
      quickSort(arr,0,n-1);
    }
}

bool isEqual(int arr[],int arr1[],int n)
{
  for(int i = 0; i < n; i++)
  {
    if(arr[i]!=arr1[i])
        return false;
  }
  return true;
}

void print(int *arr, int n)
{
    std::cout << "[";
    for (int i = 0 ; i < n ; i++)
    {
        std::cout << arr[i] << ",";
    }
    std::cout << "]" << std::endl;
}

void TestHeapSort()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr1[] = {5, 6, 7, 11, 12, 13};
    int N = sizeof(arr) / sizeof(arr[0]);
    print(arr, N);
    heapSort(arr, N);
    if(isEqual(arr,arr1,N))
        cout << "Heapsort Test passed" << endl;
    else
        cout<< "HeapSort Test Fail" << endl;
    cout << "Sorted array is \n";
    print(arr, N);
}

void TestMergeSort()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr1[] = {5, 6, 7, 11, 12, 13};
    int N = sizeof(arr) / sizeof(arr[0]);
    print(arr, N);
    int *x = mergesort(arr, N);
    if(isEqual(x,arr1,N))
        cout << "Mergesort Test passed" << endl;
    else
        cout<< "MergeSort Test Fail" << endl;
    cout << "Sorted array is \n";
    print(x, N);
}

void TestInsertionSort()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr1[] = {5, 6, 7, 11, 12, 13};
    int N = sizeof(arr) / sizeof(arr[0]);
    print(arr, N);
    insertionSort(arr, N);
    if(isEqual(arr,arr1,N))
        cout << "Insertionsort Test passed" << endl;
    else
        cout<< "InsertionSort Test Fail" << endl;
    cout << "Sorted array is \n";
    print(arr, N);
}

void TestQuickSort()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr1[] = {5, 6, 7, 11, 12, 13};
    int N = sizeof(arr) / sizeof(arr[0]);
    print(arr, N);
    quickSort(arr, 0,N-1);
    if(isEqual(arr,arr1,N))
        cout << "Quicksort Test passed" << endl;
    else
        cout<< "QuickSort Test Fail" << endl;
    cout << "Sorted array is \n";
    print(arr, N);
}

void TestHybridsort()
{
    int arr[] = { 12, 11, 13, 5, 6, 7, 8, 1, 13, 10, 3};
    int arr1[] = {1, 3, 5, 6, 7, 8, 10, 11, 12, 13, 13};
    int N = sizeof(arr) / sizeof(arr[0]);
    print(arr, N);
    int *y = hybridsort(arr,N);
    if(isEqual(y,arr1,N))
        cout << "HybridSort Test passed" << endl;
    else
        cout<< "HybridkSort Test Fail" << endl;
    cout << "Sorted array is \n";
    print(y, N);
}

int main()
{
    TestHeapSort();
    TestMergeSort();
    TestInsertionSort();
    TestQuickSort();
    TestHybridsort();
    chrono::nanoseconds zero(0);
    chrono::nanoseconds heapresults[99];
    chrono::nanoseconds mergeresults[99];
    chrono::nanoseconds insertionresults[99];
    chrono::nanoseconds quickresults[99];
    chrono::nanoseconds hybridresults[99];
    fill(heapresults,heapresults+99,zero);
    fill(mergeresults,mergeresults+99,zero);
    fill(insertionresults,insertionresults+99,zero);
    fill(quickresults,quickresults+99,zero);
    fill(hybridresults,hybridresults+99,zero);
    int randomDigits[9900] = {};
    int tmp[9900] = {};

    long times = 10;
    for (long i = 0 ; i < times ; i++)
    {
        srand(time(nullptr));
        for(int i=0; i<9900; i++)
        {
            randomDigits[i] = rand();
        }
        cout << endl;
        for(int i=0; i<99; i++)
        {
            int n = 10*(i+1);

            copy(randomDigits,randomDigits + n, tmp);
            auto start = chrono::steady_clock::now();
            heapSort(tmp,n);
            auto end = chrono::steady_clock::now();
            chrono::nanoseconds time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start);
            heapresults[i]+=time_taken;

            copy(randomDigits,randomDigits + n, tmp);
            start = chrono::steady_clock::now();
            mergesort(tmp,n);
            end = chrono::steady_clock::now();
            time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start);
            mergeresults[i]+=time_taken;

            copy(randomDigits,randomDigits + n, tmp);
            start = chrono::steady_clock::now();
            insertionSort(tmp,n);
            end = chrono::steady_clock::now();
            time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start);
            insertionresults[i]+=time_taken;

            copy(randomDigits,randomDigits + n, tmp);
            start = std::chrono::steady_clock::now();
            quickSort(tmp,0,n-1);
            end = chrono::steady_clock::now();
            time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start);
            quickresults[i]+=time_taken;

            copy(randomDigits,randomDigits + n, tmp);
            start = std::chrono::steady_clock::now();
            hybridsort(tmp,n);
            end = chrono::steady_clock::now();
            time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start);
            hybridresults[i]+=time_taken;
        }
    }
    for(int i=0; i<99; i++)
    {
        int n = 10*(i+1);
        cout << n << " ";
        cout << heapresults[i].count()/times << " ";
        cout << mergeresults[i].count()/times << " ";
        cout << insertionresults[i].count()/times << " ";
        cout << quickresults[i].count()/times << " ";
        cout << hybridresults[i].count()/times << endl;
    }
    return 0;
}
