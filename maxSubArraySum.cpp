#include <iostream>
using namespace std;
void maxSubArraySum(int arr[], int n, int k, int x)
{
    int sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if (sum < x)
    {
        ans = sum;
    }
    for (int i = k; i < n; i++)
    {
        sum -= arr[i - k];
        sum += arr[i];
        if (sum < x)
        {
            ans = max(ans, sum);
        }
    }
    cout << "max subArray sum :" << sum << endl;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    maxSubArraySum(arr,n,3,20);
    return 0;
}