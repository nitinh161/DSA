#include<iostream>
#include<climits>
using namespace std;
int MaxSum(int arr[],int n){
int currsum[n+1];
currsum[0]=0;
for(int i=1;i<=n;i++)
{
    currsum[i]=currsum[i-1]+arr[i-1];
}
int maxSum=INT_MIN;

int curr=0;
for(int i=0;i<=n;i++)
{
    if(currsum[i]>maxSum)
    {
        maxSum=currsum[i];
    }
}
return maxSum;
}
int main(){
    int arr[]={1,3,5,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=MaxSum(arr,n);
    cout<<"Max :"<<max;
    return 0;
}