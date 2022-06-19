#include <iostream>
#include <vector>
#include <map>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    map<int, int> mp;

    int currsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currsum += nums[i];
        if (nums.size() == 1)
        {
            if (nums[i] == k)
            {
                return 1;
                break;
            }
        }
        if (currsum - k == 0)
        {
            mp[k]++;
        }
        if (mp.find(currsum - k) != mp.end())
        {
            mp[k]++;
        }
        mp[currsum] = i;
    }
    return mp[k];
}
int main()
{
    vector<int> n = {1};
    cout << subarraySum(n, 1);
    return 0;
}