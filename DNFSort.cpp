#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int l,int h){
    int temp=arr[l];
    arr[l]=arr[h];
    arr[h]=temp;
}
void dnf(int arr[],int n)
{
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(arr[mid]==0)
            {
                swap(arr,low,mid);
                low++;mid++;
            }
            else if(arr[mid]==1)
            {
                mid++;
            }
            else {
                swap(arr,mid,high);
                high--;
            }
        }
    }
int main(){
    int arr[7]={0,1,2,2,0,1,2};
    dnf(arr,7);
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}