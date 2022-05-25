#include<iostream>
using namespace std;
void instertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    { 
        int j=i-1;
        int current=arr[i];
        while(arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}
void print (int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    instertionSort(arr,n);
    print(arr,n);
    return 0;
}