/*
ID:The One
TASK:range
LANG:C
*/
#include<stdio.h>
int main()
{
    freopen("range.in","r",stdin);
    freopen("range.out","w",stdout);
    int data[2][255][255]={0};
    int i,j,k,n,temp,now,after,sum;
    char s[260];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",s);
        for(j=1;j<=n;j++)data[0][i][j]=s[j-1]-48;
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)printf("%d ",data[0][i][j]);
        printf("\n");
    }*/
    /*for(i=k;i<=n;i++)for(j=k;j<=n;j++)
    {
        if(data[0][i-1][j]==1&&data[0][i-1][j-1]==1&&data[now][i][j-1]==1)data[after][i][j]=1;
    }*/
    now=0;
    after=1;
    for(k=2;k<=n;k++)
    {
        sum=0;
        for(i=k;i<=n;i++)for(j=k;j<=n;j++)data[after][i][j]=0;
        for(i=k;i<=n;i++)for(j=k;j<=n;j++)
        {
            if(data[now][i][j]==1&&data[now][i-1][j]==1&&data[now][i-1][j-1]==1&&data[now][i][j-1]==1){data[after][i][j]=1;sum++;}
        }
        //printf("-------------------------------\n");
        if(sum>0)printf("%d %d\n",k,sum);
        else break;
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)printf("%d ",data[now][i][j]);
            printf("\n");
        }
        printf("\n\n");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)printf("%d ",data[after][i][j]);
            printf("\n");
        }*/
        temp=now;
        now=after;
        after=temp;
    }
    return 0;
}
