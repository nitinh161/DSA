#include <iostream>
#include <cmath>
using namespace std;
bool isPerfectNumber(int n)
{
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                sum += i;
            }
            else
                sum += i + n / i;
        }
    }
    if (sum == n && n != 1)
    {
        return true;
    }
    return false;
}
int maxSum(int arr[], int n, int k)
{
    int sum = 0;
    int res = 0;
    if (n < k)
    {
        cout << "invalid value" << endl;
        return -1;
    }
    for (int i = 0; i < k; i++)
    {
        res += arr[i];
    }
    sum = res;
    for (int i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i - k];
        res = max(res, sum);
    }
    return res;
}
int maxNoOfPerfect(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (isPerfectNumber(arr[i]))
        {
            arr[i] = 1;
        }
        else
            arr[i] = 0;
    }
    return maxSum(arr, n, k);
}
int main()
{
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << "Sum Of Perfect number :" << maxNoOfPerfect(arr, n, k);

    return 0;
}