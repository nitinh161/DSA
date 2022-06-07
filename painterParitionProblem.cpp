#include <iostream>
#include <limits.h>
using namespace std;
int findFessible(int arr[], int n, int m, int min)
{
    int painter = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > min)
        {
            sum = arr[i];
            painter++;
        }
    }
    return painter;
}
int painterPartion(int arr[], int n, int m)
{
    int sum = 0, k_max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        k_max = max(k_max, arr[i]);
        sum += arr[i];
    }
    int start = k_max, end = sum, mid;
    while (start < end)
    {
        mid = (start + end) / 2;
        int painter = findFessible(arr, n, m, mid);
        if (painter <= m)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}
int main()
{
    int boards[] = {10, 20, 30, 40};
    int n = sizeof(boards) / sizeof(boards[0]);
    int m = 2;
    cout << "min time paint max board by one painter : " << painterPartion(boards, n, m);
    return 0;
}