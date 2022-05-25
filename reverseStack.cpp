#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topele);
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, ele);
}
void PrintStack(stack<int> s)
{
    if (s.empty())
        return;

    int x = s.top();

    s.pop();

    cout << x << ' ';

    PrintStack(s);

    s.push(x);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    PrintStack(st);

    return 0;
}