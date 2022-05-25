#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum=0;
    int temp=n;
    while(n)
    {
        int lastdigit=n%10;
        sum+=(lastdigit*lastdigit*lastdigit);   
        n=n/10;
        
    }
    if(sum==temp)
    {
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}