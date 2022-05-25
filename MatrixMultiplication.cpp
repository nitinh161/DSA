#include <iostream>
using namespace std;

int main()
{
    int n1 = 3, n2 = 3, n3 = 3;
    int m1[n1][n2]={{1,2,3},
                    {1,2,3},
                    {1,2,3}};
    int m2[n2][n3]={{1,2,3},
                    {1,2,3},
                    {1,2,3}};
    int res[n1][n3];
    
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            res[i][j]=0;
            for(int k=0;k<n2;k++)
            {
                res[i][j]+=(m1[i][k] * m2[k][j]);
            }
        }
    }
    cout<<"result"<<endl;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            cout<<res[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}