#include<iostream>
using namespace std;
string dup(string s)
{
    if(s.length()==0)
    {
        return "";

    }
    char ch=s[0];
    cout<<"ch "<<ch<<endl;
    string ans=dup(s.substr(1));
    cout<<"ans " <<ans<<endl;
    if(ch==ans[0])
    {
        return ans;
    }
    return(ch+ans);
}
int main(){
    string s="aaaabbbbccccdddd";
    cout<<dup(s);
    return 0;
}