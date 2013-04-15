/*
ID:The One
TASK:shopping
LANG:C
*/
#include<stdio.h>
#include<string.h>
int dp[6][6][6][6][6],cheapcase[105][7],cheapbuy[105][7],cheapvalue[105],data[1005][3],number[7],rember[1005];
int main()
{
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    int s,b,n,i,j,sign[6],i1,i2,i3,i4,i5,x;
    int min(int x,int y);
    scanf("%d",&s);
    for(i=0;i<s;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",x);
            scanf("%d",cheapcase[i][x]);
        }
        scanf("%d",&cheapvalue[i]);
    }
    scanf("%d",&b);
    for(i=1;i<=b;i++)
    {
        scanf("%d",&number[i]);
        rember[number[i]]=i;
        scanf("%d%d",&data[number[i]][0],&data[number[i]][1]);
    }
    //for(i=0;i<b;i++)printf("%d %d\n",number[i],rember[number[i]]);
    for(i1=0;i1<=data[number[1]][0];i1++)
    for(i2=0;i2<=data[number[2]][0];i2++)
    for(i3=0;i3<=data[number[3]][0];i3++)
    for(i4=0;i4<=data[number[4]][0];i4++)
    for(i5=0;i5<=data[number[5]][0];i5++)dp[i1][i2][i3][i4][i5]=i1*data[number[1]][1]+i2*data[number[2]][1]+i3*data[number[3]][1]+i4*data[number[4]][1]+i5*data[number[5]][1];

    for(i1=0;i1<=data[number[1]][0];i1++)
    for(i2=0;i2<=data[number[2]][0];i2++)
    for(i3=0;i3<=data[number[3]][0];i3++)
    for(i4=0;i4<=data[number[4]][0];i4++)
    for(i5=0;i5<=data[number[5]][0];i5++)printf("%d,%d,%d,%d,%d=%d\n",i1,i2,i3,i4,i5,dp[i1][i2][i3][i4][i5]);

    dp[0][0][0][0][0]=0;
    for(i=0;i<s;i++)
    {
        memset(sign,0,sizeof(sign));
        sign[1]=cheapcase[i][number[1]];
        sign[2]=cheapcase[i][number[2]];
        sign[3]=cheapcase[i][number[3]];
        sign[4]=cheapcase[i][number[4]];
        sign[5]=cheapcase[i][number[5]];
        printf("%d,%d,%d,%d,%d-----------\n",sign[1],sign[2],sign[3],sign[4],sign[5]);
        for(i1=sign[1];i1<=data[number[1]][0];i1++)
        for(i2=sign[2];i2<=data[number[2]][0];i2++)
        for(i3=sign[3];i3<=data[number[3]][0];i3++)
        for(i4=sign[4];i4<=data[number[4]][0];i4++)
        for(i5=sign[5];i5<=data[number[5]][0];i5++)
        {
            dp[i1][i2][i3][i4][i5]=min(dp[i1][i2][i3][i4][i5],dp[i1-sign[1]][i2-sign[2]][i3-sign[3]][i4-sign[4]][i5-sign[5]]+cheapvalue[i]);
            printf("%d,%d,%d,%d,%d=%d\n",i1,i2,i3,i4,i5,dp[i1][i2][i3][i4][i5]);
        }
    }
    printf("%d\n",dp[data[1][0]][data[number[2]][0]][data[number[3]][0]][data[number[4]][0]][data[number[5]][0]]);
    return 0;
}

int min(int x,int y)
{
    if(x>y)return y;
    else return x;
}
