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
    cout<<"Fatorial of "<<n<<" : "<<factorial(n);
    return 0;
}