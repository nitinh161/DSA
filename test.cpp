#include <iostream>
using namespace std;

int main()
{
    char arr[] = {'A', 'B', 'C'};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "n:" << n << endl;
    for (int i = 0; i < (1 << n); i++)
    {
        cout << "i: " << i << endl;
        for (int j = 0; j < n; j++)
        {

            if (i & (1 << j))
            {
                cout << endl
                     << arr[j] << " ";
                cout << "j:" << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}