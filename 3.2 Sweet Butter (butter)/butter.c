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
    int result[805];
    int sum[805]={0};
    int inn[805];
    int spfa[200000];
    int i,j,k,n,p,c,x,y,head,end;
    fscanf(in,"%d%d%d",&n,&p,&c);
    for(i=1;i<=p;i++)cow[i]=0;
    for(i=1;i<=n;i++){fscanf(in,"%d",&x);cow[x]++;}
    for(i=1;i<=c;i++)
    {
        fscanf(in,"%d%d",&x,&y);
        fscanf(in,"%d",&way[x][y]);
        way[y][x]=way[x][y];
    }
    /*for(i=1;i<=p;i++)
    {
        for(j=1;j<=p;j++)fprintf(out,"%d ",way[i][j]);
        fprintf(out,"\n");
    }*/
    for(i=1;i<=p;i++)sum[i]=9999999;
    for(k=1;k<=p;k++)
    {
        //if(cow[k]==0)continue;
        for(i=1;i<=p;i++)result[i]=9999999;
        for(i=1;i<=p;i++)inn[i]=0;
        result[k]=0;
        head=0;
        end=1;
        spfa[head]=k;
        inn[k]=1;
        for(;head<end;)
        {
            for(i=1;i<=p;i++)
            {
                if(way[spfa[head]][i]!=0&&result[i]>result[spfa[head]]+way[spfa[head]][i])
                {
                    result[i]=result[spfa[head]]+way[spfa[head]][i];
                    if(inn[i]==0)
                    {
                        spfa[end]=i;
                        end++;
                    }
                }
            }
            inn[spfa[head]]=0;
            head++;
        }
        sum[k]=0;
        for(i=1;i<=p;i++)if(result[i]!=9999999&&cow[i]>0)sum[k]+=result[i]*cow[i];
        /*fprintf(out,"\n%d\n",sum[k]);
        for(i=1;i<=p;i++)fprintf(out,"%4d ",result[i]);
        fprintf(out,"\n\n");*/
    }
    /*for(i=1;i<=p;i++)fprintf(out,"%d ",sum[i]);
    fprintf(out,"\n");*/
    int max=9999999;
    for(i=1;i<=p;i++)
    {
        if(sum[i]!=9999999&&sum[i]<max)max=sum[i];
    }
    fprintf(out,"%d\n",max);
    return 0;
}
