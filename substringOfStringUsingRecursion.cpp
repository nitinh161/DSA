#include<iostream>
#include<string>
using namespace std;
void subseq(string s,string ans)
{
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string ros=s.substr(1);
    cout<<"ch: "<<ch<<endl;
    cout<<"ans: "<<ans<<endl;
    subseq(ros,ans);
    cout<<"ch: "<<ch<<endl;
    cout<<"ans: "<<ans<<endl;
    subseq(ros,ans+ch);
    cout<<"ch: "<<ch<<endl;
    cout<<"ans: "<<ans<<endl;
}
int main(){
    string s="abc";
    string ans="";
    subseq(s,ans);
    return 0;
}