#include <iostream>
#include <algorithm>
using namespace std;
bool isFesible(int mid, int arr[], int n, int k)
{
    int element = 1;
    int pos = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            element++;
            if (element == k)
            {
                return true;
            }
        }
    }
    return false;
}
int largestMinDist(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int left = 1;
    int right = arr[n - 1];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFesible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}
int main()
{
    int arr[] = {1, 2, 4, 8, 11};
    int n = 5, k = 3;
    cout << "largest Min Distance :" << largestMinDist(arr, n, k);

    return 0;
}