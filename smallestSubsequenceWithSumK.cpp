#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, sum = 0, count = 0;
    cin >> n >> k;
    vector<int> arr(n);
    priority_queue<int,vector<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        
    }
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
        count++;

        if (sum >= k)
        {
            break;
        }
    }
    if (sum < k)
    {
        cout << "-1" << endl;
    }
    else
        cout << count << endl;
    return 0;
}