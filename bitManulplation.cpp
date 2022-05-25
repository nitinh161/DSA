#include<iostream>
using namespace std;
int getbit(int n,int pos)
{
    return (1<<pos) &n;
}
int setbit(int n,int pos)
{
    return n | (1<<pos);
}
int clearbit(int n,int pos)
{
    int mask=~(1 << pos);
    return (n&mask);
}
int main(){
    int n=100110101;
    // int mask=1<<5;
    // int num=n and mask;
    // cout<<num;
    int num=getbit(n,8);
    // int num2=setbit(n,7);
    // int num3=clearbit(n,2);
    cout<<num;
    // cout<<num3;
    return 0;
}