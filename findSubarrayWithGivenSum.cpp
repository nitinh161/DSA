#include <iostream>
#include <map>
using namespace std;
void subArrayWithGivenSum(int arr[], int n, int sum)
{
    map<int, int> mp;
    int start = 0, end = -1;

    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum - sum == 0)
        {
            start = 0;
            end = i;
            break;
        }
        if (mp.find(currsum - sum) != mp.end())
        {
            start = (mp[currsum - sum]) + 1;
            end = i;
            break;
        }
        mp[currsum]=i;
    }
    if (end == -1)
    {
        cout << "No SubArray Found" << endl;
    }
    else
    {
        cout << start << " " << end << endl;
    }
}
int main()
{
    int arr[] = {10, 15, -5, 15, -10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    subArrayWithGivenSum(arr, n, 5);
    return 0;
}