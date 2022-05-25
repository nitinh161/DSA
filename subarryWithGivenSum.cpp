#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 12;
    int i = 0, j = 0, st = -1, en = -1, sum = 0;
    while (j < n && sum + arr[j] <= s)
    {
        sum += arr[j];
        j++;
    }
    if (sum == s)
    {
        cout << i + 1 << " " << j << endl;
        return 0;
    }
    while (j < n)
    {
        sum += arr[j];
        while (sum > s)
        {
            /* code */
            sum -= arr[i];
            i++;
        }
        if (sum == s)
        {
            st = i + 1;
            en = j + 1;
            break;
        }
        j++;
    }
    cout << st << " " << en << endl;
    return 0;
}