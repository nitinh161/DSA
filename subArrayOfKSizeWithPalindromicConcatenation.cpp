#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPalindromic(int n)
{

    int temp = n, number = 0;
    while (temp)
    {
        number = number * 10 + temp % 10;
        temp = temp / 10;
    }
    if (number == n)
    {
        return true;
    }
    return false;
}
void findPalindromicSubarray(vector<int> arr, int k)
{
    pair<int, int> ans;
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i];
    }
    if (isPalindromic(num))
    {
        return num;
    }
    for (int j = k; j < arr.max_size(); j++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[i];

        if (isPalindromic(num))
        {
            return j - k + 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 3, 1, 5, 1, 5, 1};
    return 0;
}