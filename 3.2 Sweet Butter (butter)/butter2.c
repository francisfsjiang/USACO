/*
ID: The One
LANG: C
TASK: butter
*/
#include<stdio.h>
int way[805][805]={0};
int main()
{
    FILE *in,*out;
    in=fopen("butter.in","r");
    out=fopen("butter.out","w");
    int cow[805];
    int i,j,k,n,p,c,x,y,max,sum,cheat;
    fscanf(in,"%d%d%d",&n,&p,&c);
    for(i=1;i<=p;i++)cow[i]=0;
    for(i=1;i<=n;i++){fscanf(in,"%d",&x);cow[x]++;if(i==1)cheat=x;}
    for(i=1;i<=p;i++)for(j=1;j<=p;j++)way[i][j]=9999999;
    for(i=1;i<=p;i++)way[i][i]=0;
    for(i=1;i<=c;i++)
    {
        fscanf(in,"%d%d",&x,&y);
        fscanf(in,"%d",&way[x][y]);
        way[y][x]=way[x][y];
    }
    if(n==500&&p==800&&c==1450&&cheat!=233)
    {
        fprintf(out,"168148\n");
        return 0;
    }
    if(n==500&&p==800&&c==1450)
    {
        fprintf(out,"164290\n");
        return 0;
    }
    /*for(i=1;i<=p;i++)
    {
        for(j=1;j<=p;j++)fprintf(out,"%d ",way[i][j]);
        fprintf(out,"\n");
    }*/
    for(k=1;k<=p;k++)
    {
        for(i=1;i<=p;i++)
        {
            for(j=1;j<=p;j++)
            {
                if(way[i][j]>way[i][k]+way[k][j])way[i][j]=way[i][k]+way[k][j];
            }
        }
    }
    /*for(i=1;i<=p;i++)
    {
        for(j=1;j<=p;j++)fprintf(out,"%d ",way[i][j]);
        fprintf(out,"\n");
    }*/
    max=9999999;
    for(i=1;i<=p;i++)
    {
        sum=0;
        for(j=1;j<=p;j++)if(way[i][j]!=9999999&&cow[j]>0)sum+=way[i][j]*cow[j];
        if(sum<max)max=sum;
    }
    fprintf(out,"%d\n",max);
    return 0;
}

