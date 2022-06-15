#include <iostream>
using namespace std;
void heapify(int arr[], int n, int idx)
{
    int maxIdx = idx;
    int l = idx * 2 + 1;
    int r = idx * 2 + 2;

    if (l < n && arr[l] > arr[maxIdx])
    {
        maxIdx = l;
    }
    if (r < n && arr[r] > arr[maxIdx])
    {
        maxIdx = r;
    }
    if (maxIdx != idx)
    {
        swap(arr[idx], arr[maxIdx]);
        heapify(arr, n, maxIdx);
    }
}
void heapSort(int arr[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void buildHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void printHeap(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);
    heapSort(arr,n);

    printHeap(arr, n);
    return 0;
}