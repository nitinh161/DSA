#include<iostream>
using namespace std;
numberOfOnes(int n)
{
    int count=0;
    while(n)
    {
        n=n&n-1;
        count++;
    }
    return count;
}
int main(){
    int n;
    cin>> n;
    cout<<numberOfOnes(n);
    return 0;
}