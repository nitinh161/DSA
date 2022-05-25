#include<iostream>
using namespace std;
string MoveAllX(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch=s[0];
    string ans=MoveAllX(s.substr(1));
    if(ch== 'x'){
        return ans+ch;
    }
    return ch+ans;
}
int main(){
    string s="xnxixtxixn";
    cout<<MoveAllX(s);
    return 0;
}