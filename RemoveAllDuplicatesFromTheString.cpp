#include<iostream>
using namespace std;
string removeDuplicate(string s)
{
    if(s.size()==0)
    {
        return "";
    }
    char ch=s[0];
    string ans=removeDuplicate(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return ch+ans;
}
int main(){
    string s;
    cin>>s;
    cout<<removeDuplicate(s);
    return 0;
}