#include<iostream>
using namespace std;
int factorial(int n)
{
    int fact=1;
    while(n >= 1)
    {
        fact *= n;
        n--;
    }
    return fact;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<factorial(i)/(factorial(i-j)*factorial(j))<<" ";
        }cout<<endl;
    }
    return 0;
}