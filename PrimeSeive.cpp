#include<iostream>
using namespace std;
void primeSeive(int n)
{
    int prime[101]={0};
    for(int i=2;i<=n;i++)
    {
        for(int j=i*i;j<=n;j+=i)
        {
            prime[j]=1;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i] != 1)
        {
            cout<<i<<" ";
        }
    }

}
int main(){
    int n=100;
    primeSeive(n);
    return 0;
}