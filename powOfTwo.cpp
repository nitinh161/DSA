#include<iostream>
using namespace std;
int powOfTwo(int n)
{
    return n && !(n&n-1);
}
int main(){
    cout<<powOfTwo(5);
    return 0;
}