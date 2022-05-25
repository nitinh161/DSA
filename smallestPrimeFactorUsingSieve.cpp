#include<iostream>
using namespace std;
void primeFactor(int n)
{
    int pf[101]={0};
    for(int i=2;i<=n;i++)
    {
        pf[i]=i;
    }
    for (int i = 2; i <= n; i++)
    {
        if(pf[i] == i)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(pf[j]==j)
                {
                    pf[j]=i;
                }
            }
        }
    }
    while(n !=1 )
    {
        cout<<pf[n]<<" ";
        n=n/pf[n];
    }
    

}
int main(){
    int n=50;
    primeFactor(n);
    return 0;
}