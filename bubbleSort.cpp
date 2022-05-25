#include <iostream>
using namespace std;
void bubleSort(int arr[], int size)
{
    int count = 1;
    while (count < size)
    {
        for (int i = 0; i < size - count; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }count++;
    }

}
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {

    cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubleSort(arr,n);
    print(arr,n);
    return 0;
}