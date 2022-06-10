#include <iostream>
using namespace std;
int findPeekElement(int arr[], int low, int high, int n)
{
    int mid = low + (high - low) / 2;
    if (mid == 0 || arr[mid - 1] < arr[mid] && (mid == n - 1 || arr[mid + 1] < arr[mid]))
    {
        return mid;
    }
    else if (mid > 0 && arr[mid - 1] > arr[mid])
    {
        return findPeekElement(arr, low, mid - 1, n);
    }
    else
    {
        return findPeekElement(arr, mid + 1, high, n);
    }
}
int main()
{
    int arr[] = {1, 2, 4, 20, 5, 2};
    int n = 6;
    cout << "idx :" << findPeekElement(arr, 0, n - 1, n);
    return 0;
}