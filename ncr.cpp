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
    int r;
    cin>>n>>r;
    int ncr=factorial(n)/(factorial(n-r)*factorial(r));
    cout<<ncr;
    return 0;
}