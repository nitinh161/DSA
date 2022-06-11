#include <iostream>
using namespace std;
int smallestSubArrayWithSum(int arr[], int n, int x)
{
    int sum = 0, minLength = n + 1, start = 0, end = 0;

    while (end < n)
    {
        while (sum <= x)
        {
            sum += arr[end++];
        }

        while (sum > x && start < n)
        {
            if (end - start < minLength)
            {
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Min subArray size with sum :" << smallestSubArrayWithSum(arr, n, 5);
    return 0;
}