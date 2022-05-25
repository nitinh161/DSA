#include<iostream>
using namespace std;

int main(){
    int  arr[]={10,7,4,6,8,10,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=2;
    int j=2;
    int pd=arr[1]-arr[0];
    int curr=2;
    while(j<n)
    {
        if(pd==arr[j]-arr[j-1])
        {
            curr++;
        }
        else{
            pd=arr[j]-arr[j-1];
            curr=2;
        }
        ans=max(ans,curr);
        j++;
    }
    cout<<ans;
    return 0;
}