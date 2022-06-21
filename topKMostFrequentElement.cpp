#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n = 6, k = 2;
    int arr[n] = {1, 2, 2, 2, 3, 1};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        int presentsize = freq.size();
        if (freq[arr[i]] == 0 && presentsize == k)
        {
            break;
        }
        freq[arr[i]]++;
    }
    vector<pair<int, int>> ans;
    map<int, int>::iterator it1;
    for (it1 = freq.begin(); it1 != freq.end(); it1++)
    {
        if (it1->second != 0)
        {
            pair<int, int> p;
            p.first = it1->second;
            p.second = it1->first;
            ans.push_back(p);
        }
    }
    sort(ans.begin(), ans.end(), greater<pair<int, int>>());
    vector<pair<int, int>>::iterator it;
    for (it = ans.begin(); it != ans.end(); it++)
    {
        cout << it->second << " " << it->first << endl;
    }
    return 0;
}