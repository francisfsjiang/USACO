/*
ID:The One
TASK: rockers
LANG:C++
*/
#include<iostream>
#include<cstdio>
using namespace std;
int data[25];
int dp[25][25];

int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}

int main()
{
    freopen("rockers.in","r",stdin);
    freopen("rockers.out","w",stdout);
    int n,t,m;
    cin>>n>>t>>m;
    for(int i=1;i<=n;i++)cin>>data[i];
    for(int i=1;i<=n;i++)for(int j=m;j>=1;j--)for(int k=t;k>=0;k--)
    {
        if(k>=data[i])
        {
            dp[j][k]=max(dp[j][k],dp[j][k-data[i]]+1);
            dp[j][k]=max(dp[j][k],dp[j-1][t]+1);
        }
    }
    cout<<dp[m][t]<<endl;
    return 0;
}
