#include <iostream>
using namespace std;
bool isPosible(int arr[], int n, int m, int min)
{
    int curr_sum = 0, student_req = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return false;
        }
        if (curr_sum + arr[i] > min)
        {
            student_req++;

            curr_sum = arr[i];

            if (student_req > m)
            {
                return false;
            }
        }
        else
        {
            curr_sum += arr[i];
        }
    }
    return true;
}
int minPageAllocate(int arr[], int n, int m)
{
    if (n < m)
    {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int start = 0, end = sum, mid, result;
    while (start <= end)
    {
        mid = (start + end) / 2;
        cout << "start : " << start << " mid : " << mid << " end : " << end << endl;
        if (isPosible(arr, n, m, mid))
        {
            result = mid;

            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}
int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    cout << minPageAllocate(arr, n, m);
    return 0;
}