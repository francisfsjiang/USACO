/*
ID:The One
TASK:game1
LANG:C
*/
#include<stdio.h>
#include<string.h>
int dp[105][105];
int data[105];
int sum[105][105];
int n;
int summer;

int min(int x,int y)
{
    if(x>y)return y;
    else return x;
}

int game(int s,int t)
{
    if(s==t)return data[s];
    else if(dp[s][t]!=0)return dp[s][t];
    else
    {
        dp[s][t]=sum[s][t]-min(game(s+1,t),game(s,t-1));
        return dp[s][t];
    }
}

int main()
{
    freopen("game1.in","r",stdin);
    freopen("game1.out","w",stdout);
    int n,j,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&data[i]);
    for(i=1;i<=n;i++)sum[1][i]=sum[1][i-1]+data[i];
    for(i=2;i<=n;i++)for(j=i;j<=n;j++)
    {
        sum[i][j]=sum[i-1][j]-data[i-1];
    }
    memset(dp,0,sizeof(dp));
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)printf("%d ",sum[i][j]);
        printf("\n");
    }*/
    printf("%d %d\n",game(1,n),sum[1][n]-game(1,n));
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)printf("%d ",dp[i][j]);
        printf("\n");
    }*/
    return 0;
}
