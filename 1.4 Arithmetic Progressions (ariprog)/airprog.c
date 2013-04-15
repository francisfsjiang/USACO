/*
ID: The One
LANG: C
TASK: ariprog
*/
#include<stdio.h>
#include<string.h>
#define N 130000
int vis[N],s[N];
int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    int i,j,num,a,b,sum,m,n;
    num=0;
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&m);
    sum=2*m*m;
    for(i=0;i<=m;i++)
    for(j=0;j<=i;j++)   
    vis[i*i+j*j]=1;
    for(i=0;i<=sum;i++)
    if(vis[i])
    {
        num++;
        s[num]=i;
    }
    int e=0;
    for(b=1;b*(n-1)<=sum;b++)
    for(i=1;i<=num-n+1&&s[i]+(n-1)*b<=sum;i++)
    {
        a=s[i];
        for(j=n-1;j>=1;j--)
        {
            if(!vis[a+j*b]) 
            break;
        }
        if(!j)
        {
            e++;
            printf("%d %d\n",a,b);
        }
    }
    if(!e) printf("NONE\n");
    return 0;
}
