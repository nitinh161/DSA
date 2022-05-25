#include<iostream>
using namespace std;
int getbit(int n,int pos)
{
    return n & (1<<pos);
}
int setbit(int n,int pos)
{
    return n | (1<<pos);
}
int clearbit(int n,int pos)
{
    int mask=~(1<<pos);
    return n & (mask);
}
int togglebit(int n,int pos)
{
    return n xor (1<<pos);
}
int main(){
    cout<<getbit(5,1)<<endl;
    cout<<setbit(5,1)<<endl;
    cout<<clearbit(5,1)<<endl;
    cout<<togglebit(5,1)<<endl;
    return 0;
}