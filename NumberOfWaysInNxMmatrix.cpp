#include<iostream>
using namespace std;
int count(int n,int m)
    {
        if(n==1 || m==1 )
        {
            return 1;
        }
        return count(n-1,m)+(n,m-1);
    }
int main(){
    cout<<count(3,4);
    return 0;
}