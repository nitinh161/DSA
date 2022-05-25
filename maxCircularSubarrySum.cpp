#include<iostream>
#include<climits>
using namespace std;
int kandanes(int arr[],int n)
{
    int maxsum=INT_MIN;
    int currsum=0;
    for(int i=0;i<n;i++)
    {
        currsum+=arr[i];

        if(currsum<0)
        {
            currsum=0;

        }
        maxsum=max(currsum,maxsum);
    }
    return maxsum;
}
int main(){
    int arr[]={4,-4,6,-6,10,-11,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    int wrapsum;
    int nowrapsum;
    int totalsum=0;
    nowrapsum=kandanes(arr,n);
    for(int i=0;i<n;i++)
    {
       totalsum+=arr[i];
       arr[i]=-arr[i]; 
    }
    wrapsum=totalsum+kandanes(arr,n);
    cout<<max(wrapsum,nowrapsum);

    return 0;
}