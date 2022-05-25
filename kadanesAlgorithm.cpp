#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int currsum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum < 0)
        {
            currsum = 0;
        }
        maxsum = max(maxsum, currsum);
    }
    cout << maxsum;
    return 0;
}