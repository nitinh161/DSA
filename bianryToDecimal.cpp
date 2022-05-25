#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    int x=1;
    while(n)
    {
        int ld=n%10;
        ans+=ld*x;
        x*=2;
        n=n/10;

    }
    cout<<ans;
    return 0;
}