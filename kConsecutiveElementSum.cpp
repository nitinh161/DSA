#include <iostream>
#include <climits>
using namespace std;
void kConsecutiveElementSum(int arr[], int n, int k)
{
    int sum = 0, ans = INT_MAX ;

        for (int i = 0; i < k; i++)
    {
        sum +=arr[i];
    }
    ans = min(ans, sum);
    for (int i = 1; i < n - k + 1; i++)
    {
        sum -= arr[i-1];
        sum += arr[i + k - 1];
        ans = min(ans, sum);
    }
    cout<<ans;
}
int main()
{
    int arr[] = {-2, 10, 1, 3, 2, -1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    kConsecutiveElementSum(arr, n, 3);
    return 0;
}