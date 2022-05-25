#include <iostream>
using namespace std;
void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string res =s.substr(1);
    subseq(res, ans);
    subseq(res, ans + ch);
}
int main()
{
    string s = "abc";
    string ans = "";
    subseq(s, ans);
    return 0;
}