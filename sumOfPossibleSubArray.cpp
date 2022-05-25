#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int currSum[n + 1];
    currSum[0] = 0;
    for (int i = 0; i < n+1; i++)
    {
        currSum[i] = currSum[i - 1] + arr[i - 1];
    }
    int maxsum = INT_MIN;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=0;j<i;j++)
        {
            sum=currSum[i]-currSum[j];
            maxsum=max(sum,maxsum);
        }
    }cout<<maxsum;
    return 0;
}