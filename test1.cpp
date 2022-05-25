#include<iostream>
using namespace std;
int x()
{
    int x=0;
    return x && 0;
}
int main(){
    cout<<x();
    return 0;
}