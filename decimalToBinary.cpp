#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x=1;
    int ans=0;
    while(x<=n)
    {
        x*=2;
    }
    x/=2;
    while(x>0)
    {
        int ld=n/x;
        cout<<"x= "<<x<<endl;
        cout<<"Ld :"<<ld<<endl;
        n-=ld*x;
        cout<<"n :"<<n<<endl;
        x/=2;
        ans=ans*10+ld;
    }
    cout<<ans;
    return 0;
}