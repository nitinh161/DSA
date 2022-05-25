#include<iostream>
using namespace std;
bool pairSum(int arr[],int n,int k)
{
    int low=0;
    int high=n-1;
    while(low<high)
    {
        if(arr[low]+arr[high]==k)
        {
            return true;
        }
        else if(arr[low]+arr[high]>k)
        {
            high--;
        }
        else low++;

    }
    return false;
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=15;
    int x=pairSum(arr,n,k);
    cout<<x;
    return 0;
}