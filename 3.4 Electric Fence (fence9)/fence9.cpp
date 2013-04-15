/*
ID:The One
TASK:fence9
LANG:C++
*/
#include<iostream>
#include<cstdio>
#define bug(s) cout<<#s<<s<<endl
using namespace std;

int sameif(double x,double y)
{
    if(x-y<=1e-6&&y-x<=1e-6)return 1;
    else return 0;
}

int main()
{
    freopen("fence9.in","r",stdin);
    freopen("fence9.out","w",stdout);
    int n,m,p,temp,ans=0;
    double left,right,tanl,tanr;
    int s,t;
    cin>>n>>m>>p;
    tanl=n*1.0/m;
    tanr=(n-p)*1.0/m;
    for(int i=1;i<m;i++)
    {
        temp=0;
        left=tanl*i+1;
        s=left;
        right=tanr*i+p;

        t=right;
        if(sameif(t,right))t--;
        /*bug(left);
        bug(s);
        bug(right);
        bug(t);*/
        if(t>=s)ans+=t-s+1;
        //bug(ans);
        //else break;
    }
    cout<<ans<<endl;
    return 0;
}
