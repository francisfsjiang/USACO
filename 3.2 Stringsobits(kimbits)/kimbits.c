/*
ID:The One
TASK:kimbits
LANG:C
*/
#include<stdio.h>
int dp[33][33];
int main()
{
    FILE *in,*out;
    in=fopen("kimbits.in","rt");
    out=fopen("kimbits.out","wt");
    int xx(int n,int l);
    int  i,j,n,l,sum;
    fscanf(in,"%d%d%d",&n,&l,&sum);
    for(i=0;i<=n;i++)for(j=0;j<=l;j++)dp[i][j]=0;
/*for(i=0;i<=7;i++)
{
for(j=0;j<=5;j++)fprintf(out,"%3d ",dp[i][j]);
fprintf(out,"\n");
}*/
    sum--;
    for(i=n;i>0;i--)
    {
        if(sum>0&&xx(i-1,l)<=sum)
        {
            fprintf(out,"1");
            sum-=xx(i-1,l);
            l--;
        }
        else
        {
            fprintf(out,"0");
        }
    }
    fprintf(out,"\n");
/*for(i=0;i<=7;i++)
{
for(j=0;j<=5;j++)fprintf(out,"%3d ",dp[i][j]);
fprintf(out,"\n");
}*/
    return 0;
}

int  xx(int n,int l)
{
    if(n==0||l==0)return 1;
    if(dp[n][l]!=0)return dp[n][l];
    dp[n][l]=xx(n-1,l)+xx(n-1,l-1);
    return dp[n][l];
}
