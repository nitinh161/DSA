#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    v.push_back(5);
    vector <int>::iterator it;
    // for(it=v.begin();it!=v.end();it++)
    // {
    //     cout<<*it<<" ";
    // }
    v.pop_back();
    for(auto element:v)
    {
        cout<<element<<" ";
    }cout<<endl;
    vector<int> v2(3,50);
    sort(v.begin(),v.end());
    swap(v,v2);
    for(auto element:v2)
    {
        cout<<element<<" ";
    }
    return 0;
}